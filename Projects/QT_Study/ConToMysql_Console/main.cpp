/*
Qt连接MySQL
https://blog.csdn.net/cgzhello1/article/details/8619276
Qt4.8.4 + MySQL 5.1 ，描述自己编译QMYSQL数据库插件。
QT4 一般情况下，只带了qsqlite4和qodbc两种驱动，不能直接使用mysql数据库。需要自己编译其他数据库驱动。
*/

#include <QCoreApplication>

#include <QDebug>
#include <QStringList>
#include <QSqlDatabase>

#include <QPluginLoader>
void loadMySqlDriver();

#include <QSqlQuery>


// https://blog.csdn.net/cgzhello1/article/details/8619276
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 检测 mysql 数据库驱动插件依赖版本号。
    loadMySqlDriver();

    // 检测 QT 环境目前可用的数据库驱动插件。
    qDebug() << "Available Drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
    {
        qDebug() << "\t" << driver;
    }

    // 创建、打开连接。检测是否已经安装 MYSQL，是否可以成功连接访问数据库。
    // 报错如下：
    // QSqlDatabase: QMYSQL driver not loaded
    // QSqlDatabase: available drivers: QSQLITE QMYSQL QMYSQL3 QODBC QODBC3 QPSQL QPSQL7
    qDebug() << "> QSqlDatabase dbSQL = QSqlDatabase::addDatabase(\"QMYSQL\")";
    QSqlDatabase dbSQL = QSqlDatabase::addDatabase("QMYSQL");
    // 连接到数据库服务器(MySQL server -> session)
    dbSQL.setHostName("127.0.0.1");
    dbSQL.setPort(3306);
    // 使用哪个数据库(schema,对应其实就是数据库名)
    dbSQL.setDatabaseName("sys");
    dbSQL.setUserName("root");
    dbSQL.setPassword("AM**6688");
    qDebug() << "> dbSQL.open()";
    if( !dbSQL.open() )
    {
        qDebug() << "this, warning, failure";
    }
    else
    {
        qDebug() << "this, ok, success";
    }

    // https://www.cnblogs.com/hbrw/p/6753849.html
    // 执行查询获取数据。
    QSqlQuery       query;
    query = (QSqlQuery)dbSQL;
    query.exec("select * from sys.sys_config");
    while(query.next())
    {
//        int id = query.value(0).toInt();
//        QString name = query.value(1).toString();
//        qDebug() << QString::number(id) + " : "+ name;

        QString variable = query.value(0).toString();
        QString value = query.value(1).toString();
        qDebug() << variable + " : "+ value;
    }

    return a.exec();
}

// https://www.cnblogs.com/zhaotian/p/5790068.html
void loadMySqlDriver() {
    QPluginLoader loader;
    // MySQL 驱动插件的路径
    //loader.setFileName("D:\\Qt\\Qt5.8.0\\Tools\\QtCreator\\bin\\plugins\\sqldrivers\\qsqlmysql.dll");
    //loader.setFileName("qsqlmysql.dll");
    //loader.setFileName("D:/Qt/Qt5.8.0/Tools/QtCreator/bin/plugins/sqldrivers/qsqlmysql.dll");
    //loader.setFileName("D:/Qt/Qt5.8.0/5.8/mingw53_32/plugins/sqldrivers/qsqlmysql.dll");
    loader.setFileName("D:/Qt/Qt5.8.0/5.8/mingw53_32/bin/qsqlmysql.dll");
    qDebug() << loader.load();
    qDebug() << loader.errorString();
}
