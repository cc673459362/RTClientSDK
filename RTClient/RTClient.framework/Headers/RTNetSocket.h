/*
 * @Author: jiafengchen
 * @Date: 2024-03-13 16:37:40
 * @Description:
 */
#ifndef RTCLIENT_SRC_INCLUDE_RTNETSOCKET_H_
#define RTCLIENT_SRC_INCLUDE_RTNETSOCKET_H_

#include <stdint.h>
#include <memory>
namespace RTClient {

enum RTNetSocketType {
  RTNet_SOCKET_UDP = 0,
  RTNet_SOCKET_TCP,
};


class RTNetSocketCallback {
public:
  ~RTNetSocketCallback() {}
  virtual void onConnect() = 0;

  virtual void onRecv() = 0;

  virtual void onCanWrite() = 0;

  virtual void onError(int code, int subcode, char* data) = 0;
};

// RTNetSocket: Abstract Class for SocketApi
class RTNetSocket {
 public:
  // For client, socket need to support bind(), connect(), send(),
  // close()
  // For server, socket need to support bind(), listen(), accept(), send(),
  RTNetSocket() {}
  RTNetSocket(RTNetSocketType type, std::weak_ptr<RTNetSocketCallback> cb){};
  virtual ~RTNetSocket() {}

  // todo: bind 
  // virtual bind()

  virtual int connect(const char* ip, uint16_t port) = 0;

  virtual int send(const char* data, int size) = 0;

  virtual int recv(char* data, int len) = 0;

  virtual void close() = 0;
  
};

extern std::shared_ptr<RTNetSocket> CreateRTNetSocket(RTNetSocketType type, std::weak_ptr<RTNetSocketCallback> cb);
}  // namespace RTClient
#endif  // RTCLIENT_SRC_INCLUDE_RTNETSOCKET_H_