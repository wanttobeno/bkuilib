#include <iostream>
#include "tinyxml.h"
#include "tinystr.h"
#include <windows.h>
#include <string>
using namespace std;


string GetAppPath()
{//获取应用程序根目录
    char modulePath[MAX_PATH];
	char *pdest;
    GetModuleFileNameA(NULL, modulePath, MAX_PATH);
	pdest = strrchr(modulePath,'\\');
	if (pdest)
		*pdest='\0';
    return modulePath;
}

bool CreateXmlFile(string& szFileName)
{//创建xml文件,szFilePath为文件保存的路径,若创建成功返回true,否则false
    try
    {
        //创建一个XML的文档对象。
        TiXmlDocument *myDocument = new TiXmlDocument();
        //创建一个根元素并连接。
        TiXmlElement *RootElement = new TiXmlElement("Persons");
        myDocument->LinkEndChild(RootElement);
        //创建一个Person元素并连接。
        TiXmlElement *PersonElement = new TiXmlElement("Person");
        RootElement->LinkEndChild(PersonElement);
        //设置Person元素的属性。
        PersonElement->SetAttribute("ID", "1");
        //创建name元素、age元素并连接。
        TiXmlElement *NameElement = new TiXmlElement("name");
        TiXmlElement *AgeElement = new TiXmlElement("age");
        PersonElement->LinkEndChild(NameElement);
        PersonElement->LinkEndChild(AgeElement);
        //设置name元素和age元素的内容并连接。
        TiXmlText *NameContent = new TiXmlText("周星星");
        TiXmlText *AgeContent = new TiXmlText("22");
        NameElement->LinkEndChild(NameContent);
        AgeElement->LinkEndChild(AgeContent);
        string appPath = GetAppPath();
		string fullPath = appPath;
		fullPath.append("\\");
		fullPath.append(szFileName);
        
        myDocument->SaveFile(fullPath.c_str());//保存到文件
    }
    catch (exception e)
    {
        return false;
    }
    return true;
}

bool ReadXmlFile(string& szFileName)
{//读取Xml文件，并遍历
    try
    {
        string appPath = GetAppPath();
		string fullPath = appPath;
		fullPath.append("\\");
		fullPath.append(szFileName);
        //创建一个XML的文档对象。
        TiXmlDocument *myDocument = new TiXmlDocument(fullPath.c_str());
        myDocument->LoadFile();
        //获得根元素，即Persons。
        TiXmlElement *RootElement = myDocument->RootElement();
        //输出根元素名称，即输出Persons。
        cout << RootElement->Value() << endl;
        //获得第一个Person节点。
        TiXmlElement *FirstPerson = RootElement->FirstChildElement();
        //获得第一个Person的name节点和age节点和ID属性。
        TiXmlElement *NameElement = FirstPerson->FirstChildElement();
        TiXmlElement *AgeElement = NameElement->NextSiblingElement();
        TiXmlAttribute *IDAttribute = FirstPerson->FirstAttribute();
        //输出第一个Person的name内容，即周星星；age内容，即；ID属性，即。
        cout << NameElement->FirstChild()->Value() << endl;
        cout << AgeElement->FirstChild()->Value() << endl;
        cout << IDAttribute->Value()<< endl;
    }
    catch (exception e)
    {
        return false;
    }
    return true;
}
int main()
{
    string fileName = "info.xml";
    CreateXmlFile(fileName);
    ReadXmlFile(fileName);
	return 0;
}