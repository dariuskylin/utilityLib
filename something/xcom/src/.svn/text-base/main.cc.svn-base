#include <iostream>
#include <typeinfo>

#include "Policies.h"
//#include "Timer.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

using namespace boost;
using namespace boost::mpl;
using namespace boost::mpl::placeholders;


struct IA
{ virtual int add(int x, int y) = 0; };
struct IB : public IA
{ virtual int mul(int x, int y) = 0; };
struct IC : public IA
{ virtual int sub(int x, int y) = 0; };

// shrink interfaces

template <typename Class, typename B>
struct PA : public B
{ int add(int x, int y) { return x+y; } };

template <typename Class, typename B>
struct PB : public B
{ int mul(int x, int y) { return x*y; } };

template <typename Class, typename B>
struct PC : public B
{ int sub(int x, int y) { return x-y; } };

class X;
typedef vector<IA, IB, IC> ISeq;
typedef inherit_linearly<ISeq, inherit<_2, _1> >::type IBase;
#if 0
typedef PA<X, IBase> B1;
typedef PB<X, B1> B2;
typedef PC<X, B2> B3;
#endif
typedef PC<X, PB<X, PA<X, IBase> > > B3;

// recursive
template <typename Class, typename B>
struct Empty : IBase {};

template <typename Class, template <typename, typename> class Policy>
struct Wrap
{
	template <typename B>
	struct apply
	{
		typedef Policy<Class, B> type;
	};
};

typedef Wrap<X, Empty> T0;
typedef Wrap<X, PA> T1;
typedef Wrap<X, PB> T2;
typedef Wrap<X, PC> T3;

typedef vector<T1, T2, T3> PSeq;
typedef apply<T1, IBase>::type A1;
typedef apply<T2, A1>::type A2;
typedef apply<T3, A2>::type A3;
typedef fold<PSeq, IBase, bind<_2, _1> >::type TT;

class X : public TT
{ };

class Y;
typedef Wrap<X, PA> S1;
typedef Wrap<X, PB> S2;
typedef Wrap<X, PC> S3;
typedef vector<S1, S2> PSeq1;
typedef reverse_fold<PSeq1, IBase, bind<_2, _1> >::type SS;


int main(int argc, char *argv[])
{
	X x;

	cout << sizeof(x) << endl;

	cout << x.add(5, 2) << endl;
	cout << x.mul(3, 6) << endl;
	cout << x.sub(3, 1) << endl;

	IB *p = static_cast<IB *>(&x);
	cout << p->add(5, 10) << endl;
	cout << p->mul(4, 5) << endl;

	SS *p1 = (SS*)0x8;
	cout << (long)static_cast<IB*>(p1) - 0x8 << endl;
	cout << (long)static_cast<IC*>(p1) - 0x8 << endl;
	//cout << (long)static_cast<IA*>(p1) - 0x8 << endl;

	return 0;
}

