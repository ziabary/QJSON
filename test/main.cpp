/*************************************************************************
 * QJSON : A Qt5 like JSON library that can be used in Qt 4.8+
 * Copyright (C) 2012-2014  S.Mohammad M. Ziabary <mehran.m@aut.ac.ir>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *************************************************************************/
/**
 @author S.Mohammad M. Ziabary <mehran.m@aut.ac.ir>
 */
#include <QDebug>
#include <QVariantMap>
#include <QStringList>
#include "libQJSON/JSONDocument.h"
#include "libQJSON/JSONArray.h"
#include "libQJSON/JSONObject.h"
#include "libQJSON/JSONValue.h"

int main(int argc, char *argv[])
{
    QByteArray ba("{"
                  "\"r\":{"
                     "\"login\":{"
                        "\"u\":\"Alireza\","
                        "\"p\":\"ABCD\""
                     "},"
                     "\"b\":\"Callback\""
                  "}"
               "}");
    QJsonParseError Error;
    QJsonDocument Doc = QJsonDocument::fromJson(ba, &Error);
    if (Error.error != QJsonParseError::NoError)
        qDebug()<<Error.offset<<"--"<<Error.errorString();

    if (Doc.isObject())
    {
        QString FirstObjectName =  Doc.object().begin().key();
        if (FirstObjectName == "r")
        {
            QJsonObject RPCObject = Doc.object().value("r").toObject();
            if (RPCObject.isEmpty())
                qDebug("Invalid JSON Request");
            else
            {
                QString Name;
                QVariantMap Args;
                QString CallBack;

                for (QJsonObject::const_iterator RPCObjectIter = RPCObject.constBegin();
                     RPCObjectIter != RPCObject.constEnd();
                     RPCObjectIter++)
                {
                    if (RPCObjectIter.key() == "b" &&
                        RPCObjectIter.value().isString())
                        CallBack = RPCObjectIter.value().toString();
                    else
                    {
                        Name = RPCObjectIter.key();
                        Args = RPCObjectIter.value().toVariant().toMap();
                    }

                }
                qDebug()<<Name;
                qDebug()<<Args;
                qDebug()<<CallBack;

                /*QString Name = RPCObject.begin().key();
                qDebug()<<Name;
                QJsonObject Args = RPCObject.begin().value().toObject();
                qDebug()<<Args;*/
            }
        }
        else if (FirstObjectName == "w")
        {
            qDebug("Warning");
        }
        else
            qDebug("Invalid request JSON");
    }
    else
        qDebug("Doc must be started by object");

return -1;


/*
    QByteArray ba("{\"ItemList\": {"
                    "\"Item\": [{"
                        "\"@value\": \"ow:Net Not Configured\","
                        "\"text\": \"Adapters/1/stuAdapter/LastState\""
                  "},{"
                        "\"@value\": \"o:Tuned\","
                        "\"text\": \"Adapters/1/stuAdapter/Tuner/LastState\""
                  "},{"
                        "\"@value\": \"x:NotConfigured\","
                        "\"text\": \"Adapters/1/stuAdapter/Net/LastState\""
                  "},{"
                        "\"@value\": \"x:NotConfigured\","
                        "\"text\": \"Adapters/1/stuAdapter/Net/Tab/0/stuTab/LastState\""
                  "}]"
                  "}}");
    QJsonParseError Error;
    QJsonDocument Doc = QJsonDocument::fromJson(ba, &Error);
    qDebug()<<Doc.toJson();
    if (Doc.isArray())
    {
        QJsonArray A = Doc.array();
       qDebug()<<QJsonDocument(A).toJson();
       A.append(QJsonValue(QString("13")));
       qDebug()<<QJsonDocument(A).toJson();
       QVariantMap B;
       B.insert("Salam", 14);
       A.append(QJsonObject::fromVariantMap(B));
       qDebug()<<QJsonDocument(A).toJson();
    }
    else
    {
        QJsonObject A = Doc.object();
        qDebug()<<A.toVariantMap();
        qDebug(" ");
        qDebug()<<QJsonObject::fromVariantMap(A.toVariantMap());
        qDebug(" ");
        qDebug()<<QJsonDocument(QJsonObject::fromVariantMap(A.toVariantMap()));
        qDebug(" ");


    }
*/

}
