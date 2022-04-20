# C-DesignPatterns

练习笔记。学习李建忠老师的c++设计模式课程。伪代码形式表示，后缀1代表未经过设计模式改良的代码。其他为优化后的代码。

## 重构关键技法

- 静态->动态
- 早绑定->晚绑定
- 继承->组合
- 编译时依赖->运行时依赖
- 紧耦合->松耦合

## "组件协作"模式

### 典型模式

- Template method
- Strategy
- Observer / Event

## "单一职责"模式

### 典型模式

- decorator
- bridge

## "对象创建模式"

通过“对象创建”模式绕开new，来避免对象创建（new）过程中所导致的紧耦合（依赖具体类），从而支持对象创建的稳定。它是借口抽象之后的第一步工作。

### 典型模式

- factory method
- abstract factory
- prototype
- builder