/**
 * @file FactoryTest.h
 * @comment
 * 
 * @author niexw
 */

#ifndef _XCOM_FACTORY_TEST_H_
#define _XCOM_FACTORY_TEST_H_

using xcom::ClsID;
using xcom::Factory;
using xcom::PFactory;
using xcom::meta::PolicyBase;
using xcom::meta::applyPolicy;

class Y : public Component<ComponentTraits
	< Interfaces<IA, IB, IC>::type
	, Policies<Y, PUnknown, PFactory, Add, Sub, Mul>::type> >
{ };

DEFINE_CLASS_ID(Y, "b2cfecd0-d7ad-4884-aa9f-9e948a2f338f");

class FactoryTestCases
{
public:
	void testGetObjectFactory()
	{
		IFactory* pf = Y::getObjectFactory();
		BOOST_CHECK((pf != NULL));

		ClsID clsid;
		Y::getClassID(clsid);
		BOOST_CHECK((clsid == CLSID_Y));

		ClsID const *pid;
		pid = Y::getClassID();
		BOOST_CHECK((*pid == CLSID_Y));
	}

	void testIFactory()
	{
		IFactory *pf = Y::getObjectFactory();

		IA *pa = NULL;
		long ret = pf->createInstance(NULL, IID_IA, (void**)&pa);
		BOOST_CHECK((ret == SUCCESS));
		BOOST_CHECK((pa != NULL));
		BOOST_CHECK((pa->add(3, 5) == 8));

		IB *pb = NULL;
		ret = pa->query(IID_IB, (void**)&pb);
		BOOST_CHECK((ret == SUCCESS));
		BOOST_CHECK((pb->sub(2, 3) == -1));

		IC *pc = NULL;
		ret = pb->query(IID_IC, (void**)&pc);
		BOOST_CHECK((ret == SUCCESS));
		BOOST_CHECK((pc->mul(8, 3) == 24));

		pa->release();
		pb->release();
		pc->release();
	}

	void testRefcnt()
	{
		IFactory *pf = Y::getObjectFactory();
		BOOST_CHECK((pf->addref() == 1));
		BOOST_CHECK((pf->release() == 0));
		BOOST_CHECK((pf->release() == 0));
	}
};

class FactoryTestSuite : public test_suite
{
public:
	FactoryTestSuite() : test_suite("FactoryTestSuite")
	{
		boost::shared_ptr<FactoryTestCases> instance(new FactoryTestCases());
		add(BOOST_CLASS_TEST_CASE(&FactoryTestCases::testGetObjectFactory, instance));
		add(BOOST_CLASS_TEST_CASE(&FactoryTestCases::testIFactory, instance));
		add(BOOST_CLASS_TEST_CASE(&FactoryTestCases::testRefcnt, instance));
	}
};


#endif /* _XCOM_FACTORY_TEST_H_ */
