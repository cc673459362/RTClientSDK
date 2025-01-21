/*
 * @Author: jiafengchen
 * @Date: 2024-03-31 21:04:44
 * @Description: 
 */
#ifndef RTCLIENT_SRC_INCLUDE_CONNECTION_RTNETCONNECTION_H_
#define RTCLIENT_SRC_INCLUDE_CONNECTION_RTNETCONNECTION_H_

#include <memory>
namespace RTClient {

enum RTNetConnectionType {
  RTNet_CONNECTION_TCP = 0,
};

class RTNetConnectionCallback {
public:
    virtual ~RTNetConnectionCallback() {}

  /**
   * @description: connection onopen callback. It will be called in CALLBACK thread.
   * @param {int} code
   * @param {int} subcode
   * @return {*}
   */
  virtual void onConnectionOpen() = 0;

  /**
   * @description: connection recv callback.
   * @param {char*} data
   * @param {int} len
   * @return {*}
   */
  virtual void onConnectionRecv(char* data, int len) = 0;

  /**
   * @description: connection onclose callback.
   * @param {int} code
   * @param {int} subcode
   * @return {*}
   */
  virtual void onConnectionError(int code, int subcode, char* desc) = 0;
};

class RTNetConnection {
public:
    virtual ~RTNetConnection() {}

  /**
   * @description: Connection open. It is called in caller's thread.
   * @param {char*} ip
   * @param {int} port
   * @param {RTConnectionCallback*} cb
   * @return {int}
   */
  virtual int open(const char* ip, const int port, std::weak_ptr<RTNetConnectionCallback> cb) = 0;

  /**
   * @description: Connection send data. It is called in IO thread.
   * @param {RTDataRef} data
   * @return {int}
   */
  virtual int send(char* data, int size) = 0;

  /**
   * @description: Connection close. It is called in IO thread.
   * @return {*}
   */
  virtual void close() = 0;
};

extern std::shared_ptr<RTNetConnection> CreateRTNetConnection(int type);

}


#endif