find_library(WIRINGPI_LIBRARIES NAMES WiringPi)
find_path(WIRINGPI_INCLUDE_DIRS NAMES WiringPi.h)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(WiringPi DEFAULT_MSG WIRINGPI_LIBRARIES "/usr/include")