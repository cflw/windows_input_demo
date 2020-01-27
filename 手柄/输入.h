#pragma once
#include <deque>
#include <cflw数学.h>
#include <cflw图形_d2d.h>
#include <cflw输入_xi.h>
#include <cflw时间.h>
namespace 数学 = cflw::数学;
namespace 二维 = cflw::图形::d2d;
namespace 输入x = cflw::输入::xi;
namespace 时间 = cflw::时间;
class C输入 {
public:
	static constexpr float c大圆半径 = 64;
	static constexpr float c小圆半径 = 16;
	void f初始化(HWND);
	void f销毁();
	void f计算();
	void f更新();
	void f显示();
	void f画按键(const 数学::S向量2 &, bool);
	void f画方向(const 数学::S向量2 &, const 输入x::S方向 &);
	void f画触发(const 数学::S向量2 &, float);
	void f画四键(const 数学::S向量2 &a坐标, bool a左, bool a上, bool a右, bool a下);
	二维::C二维 m二维;
	二维::tp画图形 m画图形;
	输入x::C输入 m输入;
	输入x::tp手柄 m手柄;
};