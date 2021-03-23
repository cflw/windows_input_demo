#include "输入.h"
#include "常量.h"
void C输入::f初始化(HWND a窗口) {
	m二维.f初始化(a窗口, c缩放);
	m画图形 = m二维.fc画图形();
	m画图形->fs颜色(数学::S颜色::c白);
	m画图形->fs线条宽度(2);
	m画文本 = m二维.fc画文本();
	m输入.f初始化(a窗口, c缩放);
	m笔 = m输入.f创建笔();
}
void C输入::f销毁() {
	m二维.f销毁();
	m输入.f销毁();
}
void C输入::f计算() {
	m计帧器0.f计算();
	输入w::f清除无效指针(ma笔点);
	m输入.f更新();
	while (输入w::tp笔点 v触控点 = m笔->fg新笔点()) {
		ma笔点.push_back(v触控点);
	}
}
void C输入::f更新() {
}
void C输入::f显示() {
	auto &v渲染控制 = m二维.fg渲染控制();
	v渲染控制.f开始();
	v渲染控制.f清屏();
	constexpr float c最大半径 = 50;
	for (const 输入w::tp笔点 &v点 : ma笔点) {
		const auto v点坐标 = v点->fg坐标();
		const 数学::S向量2 v坐标 = {v点坐标.x, v点坐标.y};
		m画图形->f绘制十字({v坐标, c最大半径});
		m画图形->f绘制圆形({v坐标, c最大半径});
		m画图形->f绘制圆形({v坐标, v点->fg压力() * c最大半径});
		std::wstringstream v流;
		v流 << L"x=" << v点坐标.x << L"\ny=" << v点坐标.y;
		m画文本->fs区域(v坐标);
		m画文本->f绘制文本(v流.str());
	}
	std::wstringstream v流;
	v流 << L"\n计算" << m计帧器0.fg帧速率() << L"\n渲染" << m计帧器1.f计算();
	m画文本->fs区域(数学::S向量2::c零);
	m画文本->f绘制文本(v流.str());
	v渲染控制.f结束();
}
void C输入::f消息(UINT m, WPARAM w, LPARAM l) {
	m输入.f窗口消息(m, w, l);
}