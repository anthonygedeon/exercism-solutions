#include <string_view>
#if !defined(GIGASECOND_H)
#define GIGASECOND_H

#include "boost/date_time/posix_time/posix_time.hpp"

namespace gigasecond {
	const ptime advance();

	ptime time_from_string(std::string_view);
}  // namespace gigasecond

#endif // GIGASECOND_H
