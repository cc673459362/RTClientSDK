Pod::Spec.new do |s|
  s.name             = 'RTClient'
  s.version          = '0.0.1'
  s.summary          = 'RTClient framework for iOS'
  s.description      = 'RTClient is a framework for iOS that provides advanced features.'

  # 作者和主页
  s.author           = { 'jiafengchen' => 'jiafengchen0104@gmail.com' }
  s.homepage         = 'https://github.com/cc673459362/RTClient'


  # 源代码指向 Release 中的 ZIP 文件地址
  s.source           = { :http => 'https://github.com/cc673459362/RTClient/releases/download/v0.0.7/RTClient.framework.zip' }

  # 平台和最低支持版本
  s.platform         = :ios, '9.0'

  # 解压 ZIP 文件后指定 vendored_frameworks 的相对路径
  s.vendored_frameworks = 'RTClient.framework'

  # 使用 prepare_command 解压 ZIP
  s.prepare_command = <<-CMD
    unzip RTClient.framework.zip
    rm -f RTClient.framework.zip
  CMD

  # 开启 ARC 支持
  s.requires_arc      = true
end

  