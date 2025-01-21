/*
 * @Author: jiafengchen
 * @Date: 2024-02-29 14:41:50
 * @Description: RTClient is a Client net SDK. It supports TCP/UDP, MultiPath.
 * It can be used as a RTC Client Network SDK or a simple TCP network SDK.
 */

#ifndef RTCLIENT_SRC_INCLUDE_RTCLIENT_H_
#define RTCLIENT_SRC_INCLUDE_RTCLIENT_H_

#include <memory>
namespace RTClient {

enum RTClientParam {
  // timer set
  RT_OPEN_TIMEOUT,
  RT_WRITE_TIMEOUT,
  RT_RECV_TIMEOUT,
  RT_KEEPALIVE_INTERVAL,

  // connection config
  RT_SESSION_TYPE,
};

struct RTSessionConfig {
  int tcp_num = 0;
  int udp_num = 0;
  int rudp_num = 0;
};

class RTClientCallback {
 public:
  virtual void onOpen() = 0;

  virtual void onRecv(char* data, int len) = 0;

  virtual void onError(int code, int sub_code, char* desc) = 0;
};

class RTClient {
 public:
  virtual int Open(const char* ip, const int port, std::weak_ptr<RTClientCallback> cb) = 0;

  virtual int Send(const char* data, int len) = 0;

  virtual void Close() = 0;

  virtual void SetParam(RTClientParam type, void* param, int len) = 0;
};

extern std::shared_ptr<RTClient> CreateRTClient();

}  // namespace RTClient

#endif  // RTCLIENT_SRC_INCLUDE_RTCLIENT_H_