## rtclient sdk 仓库
---
目前仅用来放iOS framework及其podspec文件。
每个版本的framework对应仓库tag。
发布新的framework版本步骤：
0. 更新framework文件
1. 修改.podspec s.version
2. 打s.version对应的tag
3. push origin
4. pod repo push xccpod RTClient.podspec --allow-warnings --verbose

xccpod是私有pod库，地址是https://github.com/cc673459362/xccpod
