#include "输入.h"
#include "常量.h"
void C输入::f初始化(HWND a窗口) {
	m二维.f初始化(a窗口, c缩放);
	m画十字 = m二维.fc画图形();
	m画十字->fs线条宽度(2);
	m画点 = m二维.fc画图形();
	m画文本 = m二维.fc画文本();
	m输入.f初始化(a窗口, c缩放);
	m输入.f创建鼠标(m鼠标);
}
void C输入::f销毁() {
	m二维.f销毁();
	m输入.f销毁();
}
void C输入::f计算() {
	m计帧器0.f计算();
	时间::t时间点 v现在 = 时间::fg现在();
	m输入.f更新();
	const auto v鼠标坐标 = m鼠标->f坐标();
	while (!ma轨迹点.empty()) {
		if (时间::f间隔(ma轨迹点.front().m时间, v现在).count() >= 1) {
			ma轨迹点.pop_front();
		} else {
			break;
		}
	}
	const auto f添加轨迹点 = [&](输入w::E鼠标按键 a按键, E颜色 a颜色) {
		if (m鼠标->f按键((输入w::t索引)a按键).f按下()) {
			ma轨迹点.push_back({数学::S向量2(v鼠标坐标.x, v鼠标坐标.y), a颜色, v现在});
		}
	};
	f添加轨迹点(输入w::E鼠标按键::e左键, e红);
	f添加轨迹点(输入w::E鼠标按键::e中键, e绿);
	f添加轨迹点(输入w::E鼠标按键::e右键, e蓝);
}
void C输入::f更新() {
}
void C输入::f显示() {
	static const 数学::S颜色 ca颜色[] = {
		{1, 0, 0, 0.5f},
		{0, 1, 0, 0.5f},
		{0, 0, 1, 0.5f},
	};
	auto &v渲染控制 = m二维.fg渲染控制();
	v渲染控制.f开始();
	v渲染控制.f清屏();
	constexpr float c十字半径 = 32;
	const auto v鼠标坐标 = m鼠标->f坐标();
	//鼠标坐标十字
	m画十字->f绘制线条(数学::S线段2::fc两点({v鼠标坐标.x - c十字半径, v鼠标坐标.y}, {v鼠标坐标.x + c十字半径, v鼠标坐标.y}));
	m画十字->f绘制线条(数学::S线段2::fc两点({v鼠标坐标.x, v鼠标坐标.y - c十字半径}, {v鼠标坐标.x, v鼠标坐标.y + c十字半径}));
	//鼠标坐标数值
	std::wstringstream v流;
	v流 << L"x=" << v鼠标坐标.x << L"\ny=" << v鼠标坐标.y << L"\n计算" << m计帧器0.fg帧速率() << L"\n渲染" << m计帧器1.f计算();
	m画文本->f绘制文本(v流.str());
	//轨迹点
	时间::t时间点 v现在 = 时间::fg现在();
	for (const auto &v轨迹点 : ma轨迹点) {
		const 数学::S颜色 &v指定色 = ca颜色[v轨迹点.m颜色];
		const float v透明度 = 1 - 时间::f间隔(v轨迹点.m时间, v现在).count();
		const 数学::S颜色 v目标色{v指定色.r, v指定色.g, v指定色.b, v指定色.a * v透明度};
		m画点->fs颜色(v目标色);
		m画点->f填充圆形(数学::S圆形(v轨迹点.m坐标, 4));
	}
	v渲染控制.f结束();
}
void C输入::f消息(UINT m, WPARAM w, LPARAM l) {
	m输入.f窗口消息(m, w, l);
}