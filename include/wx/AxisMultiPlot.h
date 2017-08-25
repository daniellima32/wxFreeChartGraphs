#ifndef __AXIS_MULTI_PLOT__
#define __AXIS_MULTI_PLOT__

#include <wx/axisplot.h>
#include <vector>

using VectorOfAxisPlot = std::vector<AxisPlot*>;

class WXDLLIMPEXP_FREECHART AxisMultiPlot : public AxisPlot
{
protected:
	VectorOfAxisPlot m_plots;
public:
	AxisMultiPlot();
	virtual ~AxisMultiPlot();
	void addPlot(AxisPlot* plot);
	void DrawGridLines(wxDC & dc, wxRect rc) override;
	void DrawData(ChartDC& cdc, wxRect rc) override;
	bool HasData() override;
	//void ChartPanelChanged(wxChartPanel *oldPanel, wxChartPanel *newPanel) override;
	//void NeedRedraw(DrawObject *obj) override;
	void DatasetChanged(Dataset *dataset) override;
	void AxisChanged(Axis *axis) override;
	void BoundsChanged(Axis *axis) override;
	void ChartMouseDown(wxPoint &pt, int key) override;
	bool AcceptAxis(Axis *axis) override;
	bool AcceptDataset(Dataset *dataset) override;
	void DrawDatasets(wxDC &dc, wxRect rc) override;
};

#endif /* __AXIS_MULTI_PLOT__ */
