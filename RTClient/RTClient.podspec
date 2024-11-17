Pod::Spec.new do |s|
    s.name             = 'RTClient'
    s.version          = '1.0.0'
    s.summary          = 'RTClient framework for iOS'
    s.source           = { :git => 'https://github.com/username/MyPrivatePodspecs.git', :tag => '1.0.0' }
  
    s.vendored_frameworks = 'RTClient.framework'  # 这里是生成的 .framework 文件
    s.requires_arc      = true
  
    # 如果你使用了其他的依赖或者配置，可以在这里添加
  end
  