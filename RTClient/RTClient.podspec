Pod::Spec.new do |s|
    s.name             = 'RTClient'
    s.version          = '1.0.0'
    s.summary          = 'RTClient framework for iOS'
  
    s.vendored_frameworks = 'RTClient.framework'  # 这里是生成的 .framework 文件
    s.requires_arc      = true
  
  end
  