#include "输入.h"
#include "常量.h"
void C输入::f初始化(HWND a窗口) {
	m二维.f初始化(a窗口, c缩放);
	m画图形 = m二维.fc画图形();
	m画图形->fs颜色(数学::S颜色::c白);
	m画图形->fs线条宽度(4);
	m手柄 = m输入.f创建手柄();
}
void C输入::f销毁() {
	m二维.f销毁();
}
void C输入::f计算() {
	m输入.f更新();
}
void C输入::f更新() {
}
void C输入::f显示() {
	auto &v渲染控制 = m二维.fg渲染控制();
	v渲染控制.f开始();
	v渲染控制.f清屏();
	//画
	constexpr float c上x = 200;
	constexpr float c上y = 50;
	constexpr float c下x = 100;
	constexpr float c下y = -100;
	constexpr float c肩y = 150;
	f画方向({-c上x, c上y}, m手柄->fg方向((输入x::t索引)输入x::E手柄方向::e左摇杆));
	f画方向({c下x, c下y}, m手柄->fg方向((输入x::t索引)输入x::E手柄方向::e右摇杆));
	f画四键({-c下x, c下y}, m手柄->fg按键((输入x::t索引)输入x::E手柄按键::e左), m手柄->fg按键((输入x::t索引)输入x::E手柄按键::e上), m手柄->fg按键((输入x::t索引)输入x::E手柄按键::e右), m手柄->fg按键((输入x::t索引)输入x::E手柄按键::e下));
	f画方向({-c下x, c下y}, m手柄->fg方向((输入x::t索引)输入x::E手柄方向::e方向键));
	f画四键({c上x, c上y}, m手柄->fg按键((输入x::t索引)输入x::E手柄按键::x), m手柄->fg按键((输入x::t索引)输入x::E手柄按键::y), m手柄->fg按键((输入x::t索引)输入x::E手柄按键::b), m手柄->fg按键((输入x::t索引)输入x::E手柄按键::a));
	f画按键({-c上x, c肩y}, m手柄->fg按键((输入x::t索引)输入x::E手柄按键::e左肩));
	f画按键({c上x, c肩y}, m手柄->fg按键((输入x::t索引)输入x::E手柄按键::e右肩));
	f画触发({-c上x, c肩y}, m手柄->fg触发((输入x::t索引)输入x::E手柄触发::e左));
	f画触发({c上x, c肩y}, m手柄->fg触发((输入x::t索引)输入x::E手柄触发::e右));
	//结束
	v渲染控制.f结束();
}
void C输入::f画按键(const 数学::S向量2 &a坐标, bool a按键) {
	constexpr float c外圆半径 = 50;
	constexpr float c内圆半径 = 40;
	if (a按键) {
		m画图形->f填充圆形({a坐标, c小圆半径});
	} else {
		m画图形->f绘制圆形({a坐标, c小圆半径});
	}
}
void C输入::f画方向(const 数学::S向量2 &a坐标, const 输入x::S方向 &a方向) {
	const float x = a方向.x * c大圆半径;
	const float y = a方向.y * c大圆半径;
	m画图形->f绘制圆形({a坐标, c大圆半径});
	m画图形->f绘制线条({a坐标, a坐标 + 数学::S向量2(x, 0)});	//x
	m画图形->f绘制线条({a坐标, a坐标 + 数学::S向量2(0, y)});	//y
	m画图形->f绘制线条({a坐标, a坐标 + 数学::S向量2::fc方向r(a方向.z * c大圆半径, 1.25f * 数学::cπ<float>)});	//z
	m画图形->f绘制圆形({a坐标 + 数学::S向量2(x, y), c小圆半径});
}
void C输入::f画触发(const 数学::S向量2 &a坐标, float a触发) {
	m画图形->f绘制线条({a坐标, a坐标 + 数学::S向量2(0, a触发 * c大圆半径)});
}
void C输入::f画四键(const 数学::S向量2 &a坐标, bool a左, bool a上, bool a右, bool a下) {
	auto f = [&](const 数学::S向量2 &a偏移, bool a按键) {
		f画按键(a坐标 + a偏移, a按键);
	};
	f(数学::S向量2(-c大圆半径, 0), a左);
	f(数学::S向量2(0, c大圆半径), a上);
	f(数学::S向量2(c大圆半径, 0), a右);
	f(数学::S向量2(0, -c大圆半径), a下);
}