#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include <QHttpMultiPart>
#include <QNetworkAccessManager>
#include <QNetworkReply>

// 函数用于上传图片文件
bool requestUploadImages(const QStringList &vsFileList, QString &strResp)
{
	// 创建一个 QHttpMultiPart 对象，用于组装请求的多部分数据
	QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

	// 遍历图片文件列表
	for (const auto &filePathIter : vsFileList)
	{
		// 创建一个 QHttpPart 对象，用于表示单个文件
		QHttpPart imagePart;

		// 获取文件信息
		QFileInfo filInfo(filePathIter);

		// 打开文件
		QFile file(filePathIter);
		if (!file.open(QIODevice::ReadOnly))
		{
			continue; // 文件打开失败，跳过当前文件
		}

		// 设置文件的 Content-Disposition 头信息，包含文件名
		imagePart.setHeader(QNetworkRequest::ContentDispositionHeader,
							QVariant(QString("form-data; name=\"uploadfile\"; filename=\"%1\"").arg(filInfo.fileName())));

		// 设置文件的 Content-Type 头信息为 image/png
		imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/png"));

		// 读取文件内容，并将其设置为 Part 的 body
		const auto &data = file.readAll();
		imagePart.setBody(data);

		// 设置文件的 Content-Length 头信息
		imagePart.setHeader(QNetworkRequest::ContentLengthHeader, QVariant(data.size()));

		// 将 Part 添加到多部分数据中
		multiPart->append(imagePart);
	}

	// 构造 URL 和请求对象
	QUrl url("http://www.csu.edu.cn");
	QNetworkRequest request(url);

	// 创建 QNetworkAccessManager 对象，用于发送网络请求
	QNetworkAccessManager manager;

	// 发送 POST 请求，并获取对应的 QNetworkReply 对象
	QNetworkReply *reply = manager.post(request, multiPart);

	// 设置 multiPart 的 parent 为 reply，当 reply 销毁时会同时销毁 multiPart
	multiPart->setParent(reply);

	// 连接 QNetworkReply 的 finished 信号，处理请求完成的回调
	QObject::connect(reply, &QNetworkReply::finished, [&reply, &strResp]
					 {
        if (reply->error() == QNetworkReply::NoError)
        {
            // 请求成功，读取响应内容
            strResp = reply->readAll();
            qDebug() << "upload file finished";
        }
        else
        {
            // 请求失败，获取错误信息
            strResp = reply->errorString();
            qDebug() << "error string:" << reply->errorString();
        } });

	// 创建一个事件循环，用于等待请求完成
	QEventLoop eventLoop;

	// 连接 QNetworkAccessManager 的 finished 信号，通知事件循环退出
	QObject::connect(&manager, &QNetworkAccessManager::finished, [&]
					 { eventLoop.quit(); });

	// 开始事件循环，直到请求完成
	eventLoop.exec();

	// 销毁 reply 对象
	reply->deleteLater();

	return true;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QString resp;
	requestUploadImages(QStringList(), resp);
	qDebug() << resp;

	return a.exec();
}
