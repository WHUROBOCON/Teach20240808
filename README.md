# Welcome to WHUROBOCON!
# <font color=orange><center>CAN通讯学习笔记</center></font>
## 8.24 LED与蜂鸣器
### 一、时钟的配置
**前期准备:**
首先是嘉立创导入标准版的pcb原理图$\rightarrow$然后是在cubemx中创立新的工程，创立的时候选择的芯片即pcb原理图的芯片型号
**Rcc：**
在cubemx的system core中找到Rcc（Reset and clock control   时钟配置，控制提供给各模块时钟信号的通断）$\rightarrow$配置Rcc与时钟$\rightarrow$在芯片原理图中找到晶振的主频$\rightarrow$HSE:外部使用$~$ ISE:Disable
### 二、LED灯的使用
#### （一）LED灯初试
首先是在芯片的原理图上找到LED是在哪一个引脚上（如pa4，pa5，pa5，pa6）$\rightarrow$然后在cubemx的图上将对应引脚改为GPIO_OUT(即输出)$\rightarrow$在左侧的GPIO模块更改一些配置，GPIO mode改为output  Push  pull（即推挽输出模式，优点：带载能力很强，让灯常亮），不上拉，不下拉$\rightarrow$在system core中找到sys，Debug改为Serival wire，便于swd下载器下载$\rightarrow$生成代码
**代码块：**
```c
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET)//参数依次为GPIO的片选（可理解为种类），选中引脚（因为之前芯片原理图上是4,5,6,7有LED灯），GPIO的状态
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);//记得放在main.c文件的while（1）中的USER CODE BERIN3
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);//然后编译下载即可
```
**补充：**
魔法棒$\rightarrow$C/C++$\rightarrow$Optimization$\rightarrow$优化等级为0
魔法棒$\rightarrow$Debug$\rightarrow$Jlink$\rightarrow$setting$\rightarrow$sw口
#### （二）流水灯
**代码块：**
```c
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);//输入高电频,也是放在while（1）中的USER CODE BERIN3
HAL_Delay(500);//延时500毫秒，加上延时才有效果
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
HAL_Delay(500);
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
HAL_Delay(500);
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
HAL_Delay(500);
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);//引脚输出低电平
HAL_Delay(500);
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
HAL_Delay(500);
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
HAL_Delay(500);
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
HAL_Delay(500);
```
### 三、蜂鸣器的使用
**前期准备:**
还是先在芯片的原理图上找到蜂鸣器beep所对应的引脚如PA8$\rightarrow$然后在cubemx的图上将对应引脚改为GPIO_OUT(即输出)$\rightarrow$在左侧的GPIO模块更改一些配置，GPIO mode改为output Push pull，下拉模式，user label（命名）
**代码块：**
~~~c
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);//也是写在while（1）里的user code begin里；同时由于我们之前选的是pa8
HAL_Delay(500);
HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);//高电频响，低电频不响
~~~
