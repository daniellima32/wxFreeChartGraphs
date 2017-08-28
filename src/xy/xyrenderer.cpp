/////////////////////////////////////////////////////////////////////////////
// Name:    xyrenderer.cpp
// Purpose: xy renderer implementation
// Author:    Moskvichev Andrey V.
// Created:    2008/11/07
// Copyright:    (c) 2008-2010 Moskvichev Andrey V.
// Licence:    wxWidgets licence
/////////////////////////////////////////////////////////////////////////////

#include <wx/xy/xyrenderer.h>

IMPLEMENT_CLASS(XYRenderer, Renderer)

XYRenderer::XYRenderer()
{
}

XYRenderer::~XYRenderer()
{
}

/*int XYRenderer::horizontalMirroring(int value)
{
	return mirroring(rcPlotBackup.x, rcPlotBackup.x + rcPlotBackup.width, value);
}

int XYRenderer::verticalMirroring(int value)
{
	return mirroring(rcPlotBackup.y, rcPlotBackup.y + rcPlotBackup.height, value);
}

int XYRenderer::mirroring(int min, int max, int value)
{
	int interval = value - min;
	return max - interval;
}

wxRect XYRenderer::getRcPlotBackup()
{
	return rcPlotBackup;
}
void XYRenderer::setRcPlotBackup(wxRect rect)
{
	rcPlotBackup = wxRect(rect);
}*/