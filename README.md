# install_game(ipa重签名后安装到手机启动、运行报错找问题调试工具)


## 工具使用说明：


1.使用xcode打开install_game工程
2.将需要找报错原因的ipa(ipa安装手机后启动闪退、运行过程中闪退)放入到app目录

<img width="469" alt="1" src="https://user-images.githubusercontent.com/19405301/160778640-03a32884-f8df-4e3e-b1b4-0da07c82b1a0.png">

2.注释掉工程中./appSign.sh脚本执行文件(注意：Target-Build-Run Script 中的./appSign.sh shell脚本要注释掉)，运行到安装到真机

<img width="1293" alt="2" src="https://user-images.githubusercontent.com/19405301/160780658-f4b1ce62-cf29-4d37-a666-b0f79f27fc6d.png">

3.运行步骤2成功后，再将工程中./appSign.sh脚本执行文件打开，打开后再将工程跑到手机上面去(运行如果 报安装 提示，重新运行安装即可)

4.执行步骤3之后，就可以在xcode输出控制台看到对应的ipa报错原因了




## 工具核心功能：
./appSign.sh




