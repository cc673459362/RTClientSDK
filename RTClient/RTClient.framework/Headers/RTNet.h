#ifndef RTCLIENT_SRC_INCLUDE_RTNET_H_
#define RTCLIENT_SRC_INCLUDE_RTNET_H_

#include <memory>
namespace RTClient {
typedef int (*RTLogCallBack)(int prio, const char* text);
extern void init(RTLogCallBack callback = nullptr);

extern void uninit();

}  // namespace RTClient
#endif  // RTCLIENT_SRC_INCLUDE_RTNET_H_


