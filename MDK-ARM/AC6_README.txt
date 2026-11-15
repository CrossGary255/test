AC6 工程说明（Keil + armclang）
================================

为什么有这个目录里的脚本？
  CubeMX 生成的 MDK-ARM 工程用的是 ARM Compiler 5 的汇编启动文件
  (startup_stm32f103xb.s, armasm 语法)。一旦把编译器切到 ARM Compiler 6，
  uVision 会把 armasm 的参数 -Wa,armasm,--pd,... 传给 armclang，于是报
  "ArmClang.exe: error: unsupported argument 'armasm' to option 'Wa,'"。

本工程已经把启动文件换成 armclang 能汇编的 GNU 语法版本，并且：
  - 编译器 = ARM Compiler 6 (armclang)
  - Asm -> Assembler = armclang (GNU syntax)
  - C/Asm/Linker 各加了一条选项，用来消掉 AC6.22 的无害告警

每次 CubeMX 点 GENERATE CODE 之后（或换了芯片之后）：
  双击本目录的 ac6_setup.bat  ->  回 Keil 里 Rebuild
  （Keil 若正开着工程，先 Project -> Close Project 再重新打开）

栈大小：
  默认 4 KB。需要更大时: ac6_setup.bat 0x2000
  堆不用设：Keil 单区内存模型下，malloc 使用 ZI 之后的全部剩余 RAM。
  FreeRTOS 用的是它自带的 heap_1..5，与本工程的堆无关。

换芯片：
  CubeMX 会生成新的 startup_xxx.s 和工程文件，直接双击 ac6_setup.bat 即可，
  脚本会自动识别新的启动文件名并生成对应的 GNU 版本（xxx_ac6.s）。

备份 / 回滚：
  GPIO.uvprojx.orig_backup          第一次运行前的工程文件
  startup_stm32f103xb_armasm.s.bak  原始的 armasm 启动文件
  把这两个文件覆盖回去即可回到 CubeMX 生成后的状态。

注意：
  不要把这个工程切回 ARM Compiler 5 —— 启动文件现在是 GNU 语法，armasm 汇编不了。