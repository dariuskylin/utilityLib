/**
 * @file FileTest.h
 * @comment
 * 
 * @author niexw
 */

#ifndef _XCOM_FILETEST_H_
#define _XCOM_FILETEST_H_

#include "File.h"

using xcom::File;
using xcom::Exception;

class FileTestCases
{
  public:
	void testConstructor()
	{
		File file;
		BOOST_CHECK(file.descriptor() == -1);

		File file1;
		file1.attach(stdin);
		BOOST_CHECK(file1.descriptor() == 0);
		File file2;
		file2.attach(stdout);
		BOOST_CHECK(file2.descriptor() == 1);

		file1.detach();
		BOOST_CHECK(file1.descriptor() == -1);
		file2.detach();
		BOOST_CHECK(file2.descriptor() == -1);
	}

	void testOpen()
	{
		File file;

		int ret = file.open("./log", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		BOOST_CHECK(ret > 2);

		string str = "hello, world";
		size_t size1 = file.write(str.c_str(), str.size());
		BOOST_CHECK(size1 == str.size());
		file.lseek(0, SEEK_SET);

		char cstr[20];
		bzero(cstr, 20);
		size1 = file.read(cstr, 20);
		BOOST_CHECK(size1 == str.size());
		BOOST_CHECK(cstr == str);

		file.close();
		BOOST_CHECK(file.descriptor() == -1);
	}

	void testReadv()
	{
		File file;

		int ret = file.open("./log", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		BOOST_CHECK(ret > 2);

		string str1 = "--hello, world\n";
		string str2 = "--bye, world\n";
		struct iovec iov[2];
		iov[0].iov_base = (void*)str1.c_str();
		iov[0].iov_len = str1.size();
		iov[1].iov_base = (void*)str2.c_str();
		iov[1].iov_len = str2.size();

		size_t size = file.writev(iov, 2);
		BOOST_CHECK(size == str1.size()+str2.size());
		file.lseek(0, SEEK_SET);

		char cstr1[10];
		char cstr2[20];
		bzero(cstr1, 10);
		bzero(cstr2, 20);
		iov[0].iov_base = (void*)cstr1;
		iov[0].iov_len = 10;
		iov[1].iov_base = (void*)cstr2;
		iov[1].iov_len = 20;
		size = file.readv(iov, 2);
		BOOST_CHECK(size == str1.size()+str2.size());

		string str3 = cstr1;
		str3 += cstr2;
		string str4 = str1;
		str4 += str2;
		BOOST_CHECK(str3 == str4);

		ret = system("rm -fr ./log");
	}
};

class FileTestSuite : public test_suite
{
  public:
	FileTestSuite() : test_suite("FileTestSuite")
	{
		boost::shared_ptr<FileTestCases> instance(new FileTestCases());
		add(BOOST_CLASS_TEST_CASE(&FileTestCases::testConstructor, instance));
		add(BOOST_CLASS_TEST_CASE(&FileTestCases::testOpen, instance));
		add(BOOST_CLASS_TEST_CASE(&FileTestCases::testReadv, instance));
	}
};

#endif /* _XCOM_FILETEST_H_ */
