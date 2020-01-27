#include "输入.h"
#include "常量.h"
void C输入::f初始化(HWND a窗口) {
	m二维.f初始化(a窗口, c缩放);
	m画图形 = m二维.fc画图形();
	m画图形->fs线条宽度(2);
	m输入.f初始化(a窗口, c缩放);
	m输入.f创建触摸(m触摸);
}
void C输入::f销毁() {
	m二维.f销毁();
	m输入.f销毁();
}
void C输入::f计算() {
	输入w::f清除松开触控点(ma触控点);
	m输入.f更新();
	while (输入w::tp触控点 v触控点 = m触摸->fg新触控点()) {
		ma触控点.push_back(v触控点);
	}
}
void C输入::f更新() {
}
void C输入::f显示() {
	auto &v渲染控制 = m二维.fg渲染控制();
	v渲染控制.f开始();
	v渲染控制.f清屏();
	for (const 输入w::tp触控点 &v : ma触控点) {
		m画图形->f绘制圆形({{v->f坐标().x, v->f坐标().y}, 50});
	}
	v渲染控制.f结束();
}
void C输入::f消息(UINT m, WPARAM w, LPARAM l) {
	m输入.f窗口消息(m, w, l);
}