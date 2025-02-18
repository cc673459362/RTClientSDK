Pod::Spec.new do |s|
  s.name             = 'RTClient'
  s.version          = '0.0.7'
  s.summary          = 'RTClient framework for iOS'
  s.description      = 'RTClient is a framework for iOS that provides advanced features.'

  # 作者和主页
  s.author           = { 'jiafengchen' => 'jiafengchen0104@gmail.com' }
  s.homepage         = 'https://github.com/cc673459362'


  # 源代码指向 Release 中的 ZIP 文件地址
  s.source           = { :git => 'https://github.com/cc673459362/RTClientSDK.git', :tag => s.version }
  # 平台和最低支持版本
  s.platform         = :ios, '12.0'

  # 解压 ZIP 文件后指定 vendored_frameworks 的相对路径
  s.vendored_frameworks = 'RTClient.framework'
  s.library           = 'c++'

  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  # 开启 ARC 支持
  s.requires_arc      = true
end
