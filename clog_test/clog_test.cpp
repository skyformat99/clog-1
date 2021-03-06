#include "stdafx.h"
#include <clog.h>
#include <boost/filesystem.hpp>

struct my_type
{
	int i;
	template<typename OStream>
	friend OStream& operator<<(OStream& os, const my_type &c)
	{
		return os << "[my_type i=" << c.i << "]";
	}
};

using namespace boost::log::trivial;

int main()
{
	CLog clog;
	clog.set_severity_min(info);
	clog.add_text_file_sink();
	//clog.add_vs_debug_output_sink();



	//while (1) {
	CLOG(trace) << L"테스트";
	CLOG(debug) << L"테스트";
	CLOG(info) << L"테스트";
	CLOG(warning) << L"테스트";
	CLOG(error) << L"테스트";
	CLOG(fatal) << my_type{ 14 };
	//}
	return 0;
}