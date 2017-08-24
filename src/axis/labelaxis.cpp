/////////////////////////////////////////////////////////////////////////////
// Name:    labelaxis.cpp
// Purpose: label axis implementation
// Author:    Moskvichev Andrey V.
// Created:    2008/11/07
// Copyright:    (c) 2008-2010 Moskvichev Andrey V.
// Licence:    wxWidgets licence
/////////////////////////////////////////////////////////////////////////////

#include <wx/axis/labelaxis.h>
#include <wx/drawutils.h>

IMPLEMENT_CLASS(LabelAxis, Axis)

class DefaultLabelColourer : public LabelColourer
{
public:
    DefaultLabelColourer();
    virtual ~DefaultLabelColourer();

    virtual wxColor GetColour(int step);

private:
    wxColor m_oddColour;
    wxColor m_evenColour;
};

DefaultLabelColourer::DefaultLabelColourer()
{
    m_oddColour = *wxLIGHT_GREY;
    m_evenColour = wxColor(100, 100, 100);
}

DefaultLabelColourer::~DefaultLabelColourer()
{
}

wxColor DefaultLabelColourer::GetColour(int step)
{
    return (step % 2) ? m_oddColour : m_evenColour;
}

int LabelAxis::horizontalMirroring(int value)
{
	return mirroring(rcPlotBackup.x, rcPlotBackup.x + rcPlotBackup.width, value);
}

int LabelAxis::verticalMirroring(int value)
{
	return mirroring(rcPlotBackup.y, rcPlotBackup.y + rcPlotBackup.height, value);
}

int LabelAxis::mirroring(int min, int max, int value)
{
	int interval = value - min;
	return max - interval;
}

/*bool LabelAxis::isOriented()
{
	return oriented;
}*/

LabelAxis::LabelAxis(AXIS_LOCATION location, bool oriented)
: Axis(location, oriented)
{
    // defaults
    m_labelLineSize = 5;
    m_labelGap = 2;

    m_labelTextFont = wxFont(wxFontInfo(9));
    m_labelTextColour = DEFAULT_AXIS_LABEL_COLOUR;
    m_labelPen = DEFAULT_AXIS_BORDER_COLOUR;
    m_verticalLabelText = false;
    m_majorLabelStep = 1;
    m_minorIntervalCount = 0;

    m_title = wxEmptyString;
    m_titleFont = wxFont(wxFontInfo(9));
    m_titleColour = DEFAULT_AXIS_LABEL_COLOUR;
    m_titleLocation = wxCENTER;

    m_visible = true;
    m_blankLabels = 0;

    m_labelColourer = new DefaultLabelColourer();

	this->oriented = oriented;
}

LabelAxis::~LabelAxis()
{
    wxDELETE(m_labelColourer);
}

wxCoord LabelAxis::GetExtent(wxDC &dc)
{
    wxSize maxLabelExtent = GetLongestLabelExtent(dc);
    wxCoord extent = m_labelLineSize + m_labelGap;

    wxSize titleExtent;

    if (m_title.Length() != 0) {
        dc.SetFont(m_titleFont);
        titleExtent = dc.GetTextExtent(m_title);
    }

    if (IsVertical()) {
        if (m_verticalLabelText) {
            extent += maxLabelExtent.y;
        }
        else {
            extent += maxLabelExtent.x;
        }

        extent += titleExtent.y; // Alan fix
        // orig: extent += titleExtent.x;
        extent += m_labelPen.GetWidth();
    }
    else {
        if (m_verticalLabelText) {
            extent += maxLabelExtent.x;
        }
        else {
            extent += maxLabelExtent.y;
        }

        extent += titleExtent.y;
        extent += m_labelPen.GetWidth();
    }
    return extent;
}

void LabelAxis::SetLabelSkip(int blankLabels)
{
    m_blankLabels = blankLabels;
}

int LabelAxis::GetLabelSkip()
{
    return m_blankLabels;
}

//Desenha os números ao lado do eixo e os seus indicadores
void LabelAxis::DrawLabels(wxDC &dc, wxRect rc)
{
    if (!HasLabels())
        return ;

    // Setup dc objects for labels and tick mark lines.
    dc.SetFont(m_labelTextFont);
    dc.SetTextForeground(m_labelTextColour);
    dc.SetPen(m_labelPen);

    wxString label;
    
    for (int majorStep = 0; !IsEnd(majorStep); majorStep++) 
    {
        double value = GetValue(majorStep);
        
        if (!IsVisible(value))
            continue;

        label = wxEmptyString;

        // Get the value for this step as a string (can be number, category etc. depending on derivative).
        GetLabel(majorStep, label);

        // Draw a tick and label at the major interval.
        DrawLabel(dc, rc, label, value, true); //desenha a label e o seu marcador

        // Calculate the value range between this label and the next (changes for non-linear axis, such as log).
        double minorInterval =  (GetValue(majorStep + 1) - GetValue(majorStep)) / m_minorIntervalCount;
        
        for (size_t minorStep = 1; minorStep <= m_minorIntervalCount; minorStep++)
        {
            double minorValue = GetValue(majorStep) + (minorInterval * minorStep);

            if (!IsVisible(minorValue))
                continue;
            
            // Draw the minor interval tick.
            DrawLabel(dc, rc, "", minorValue, false);
        }
    }
}

void LabelAxis::DrawLabel(wxDC &dc, wxRect rc, const wxString &label, double value, bool isMajorLabel)
{
    wxSize labelExtent = dc.GetTextExtent(label);

    wxCoord x, y;
    wxCoord textX, textY;
    wxCoord lineX1, lineY1;
    wxCoord lineX2, lineY2;
    int labelLineSize = isMajorLabel ? m_labelLineSize : m_labelLineSize / 2;

    if (IsVertical()) {
        y = ToGraphics(dc, rc.y, rc.height, value);

		if (oriented)
		{
			//Espelha
			y = verticalMirroring(y);
		}

        lineY1 = lineY2 = y;

        switch (GetLocation()) {
        case AXIS_LEFT:
            lineX1 = rc.x + rc.width - labelLineSize;
            lineX2 = rc.x + rc.width;

            if (m_verticalLabelText) {
                textX = lineX1 - labelExtent.y - m_labelGap;
            }
            else {
                textX = lineX1 - labelExtent.x - m_labelGap;
            }
            break;
        case AXIS_RIGHT:
            lineX1 = rc.x;
            lineX2 = rc.x + labelLineSize;

            textX = lineX2 + m_labelGap;
            break;
        default:
            return ; // BUG
        }

        if (m_verticalLabelText) {
            textY = y + labelExtent.x / 2;
        }
        else {
            textY = y - labelExtent.y / 2;
        }
    }
    else { //horizontal
        x = ToGraphics(dc, rc.x, rc.width, value);

		//Não precisa espelhar na horizontal
		/*if (oriented)
		{
			//Espelha
			x = horizontalMirroring(x);
		}*/

        lineX1 = lineX2 = x;

        switch (GetLocation()) {
        case AXIS_TOP:
            lineY1 = rc.y + rc.height - labelLineSize;
            lineY2 = rc.y + rc.height;

            if (m_verticalLabelText) {
                textY = lineY1 - m_labelGap;
            }
            else {
                textY = lineY1 - labelExtent.y - m_labelGap;
            }
            break;
        case AXIS_BOTTOM:
            lineY1 = rc.y;
            lineY2 = rc.y + labelLineSize;

            if (m_verticalLabelText) {
                textY = lineY2 + m_labelGap + labelExtent.x;
            }
            else {
                textY = lineY2 + m_labelGap;
            }
            break;
        default:
            return ; // BUG
        }

        if (m_verticalLabelText) {
            textX = x - labelExtent.y / 2;
        }
        else {
            textX = x - labelExtent.x / 2;
        }
    }

    // Draw every tick mark.
    dc.DrawLine(lineX1, lineY1, lineX2, lineY2);

    // But only draw labels for major tick intervals.
    if (isMajorLabel) 
    {
        if (m_verticalLabelText)
            dc.DrawRotatedText(label, textX, textY, 90);
        
        else
            dc.DrawText(label, textX, textY);
    }
}

void LabelAxis::DrawBorderLine(wxDC &dc, wxRect rc)
{
    wxCoord x1, y1;
    wxCoord x2, y2;

    switch (GetLocation()) {
    case AXIS_LEFT:
        x1 = x2 = rc.x + rc.width;
        y1 = rc.y;
        y2 = rc.y + rc.height;
        break;
    case AXIS_RIGHT:
        x1 = x2 = rc.x;
        y1 = rc.y;
        y2 = rc.y + rc.height;
        break;
    case AXIS_TOP:
        x1 = rc.x;
        x2 = rc.x + rc.width;
        y1 = y2 = rc.y + rc.height;
        break;
    case AXIS_BOTTOM:
        x1 = rc.x;
        x2 = rc.x + rc.width;
        y1 = y2 = rc.y;
        break;
    default:
        return ; // BUG
    }

    dc.SetPen(m_labelPen); // TODO: Consider having a different colour option.
    dc.DrawLine(x1, y1, x2, y2);
}

void LabelAxis::DrawGridLines(wxDC &dc, wxRect rc)
{
    if (!HasLabels()) 
        return ;

    for (int majorStep = 0; !IsEnd(majorStep); majorStep++) 
    {
        double value = GetValue(majorStep);
        
        if (!IsVisible(value))
            continue;

        // Draw the major interval gridline.
        dc.SetPen(m_majorGridlinePen);
        DrawGridLine(dc, rc, value);

        for (size_t minorStep = 1; minorStep <= m_minorIntervalCount; minorStep++)
        {
            // Calculate the value range between this label and the next (changes for non-linear axis, such as log).
            double minorInterval = (GetValue(majorStep + 1) - GetValue(majorStep)) / m_minorIntervalCount;
            
            double minorValue = GetValue(majorStep) + (minorInterval * minorStep);

            if (!IsVisible(minorValue))
                continue;
            
            // Draw the minor interval gridline.
            dc.SetPen(m_minorGridlinePen);
            DrawGridLine(dc, rc, minorValue);
        }
    }
}

void LabelAxis::DrawGridLine(wxDC& dc, const wxRect& rc, double value)
{
    if (IsVertical()) 
    {
        // Vertical axis, so gridlines are horizontal.
        wxCoord y = ToGraphics(dc, rc.y, rc.height - 1, value);

        if (y == rc.y || y == (rc.y + rc.height - 1))
            return;

		//y = verticalMirroring(y);
		//y = horizontalMirroring(y);

		int p1x = rc.x + 1;
		int p1y = y;
		int p2x = rc.x + rc.width - 1;
		int p2y = y;

		if (oriented)
		{
			p1x = horizontalMirroring(p1x);
			p1y = verticalMirroring(p1y);
			p2x = horizontalMirroring(p2x);
			p2y = verticalMirroring(p2y);
		}

		//Desenha as linhas da grid (internas) na vertical
        //dc.DrawLine(rc.x + 1, y, rc.x + rc.width - 1, y);

		//Desenha as linhas da grid (internas) na vertical
		dc.DrawLine(p1x, p1y, p2x, p2y);
    }
    
    else 
    {
        // Horizontal axis, so gridlines are vertical.
        wxCoord x = ToGraphics(dc, rc.x, rc.width - 1, value);

        if (x == rc.x || x == (rc.x + rc.width - 1))
            return;

		//x = horizontalMirroring(x);
		//x = verticalMirroring(x);

		int p1x = x + 1;
		int p1y = rc.y + 1;
		int p2x = x + 1;
		int p2y = rc.y + rc.height - 1;

		if (oriented)
		{
			p1x = horizontalMirroring(p1x);
			p1y = verticalMirroring(p1y);
			p2x = horizontalMirroring(p2x);
			p2y = verticalMirroring(p2y);
		}

		//Desenha as linhas da grid (internas) na horizontal
        //dc.DrawLine(x + 1, rc.y + 1, x + 1, rc.y + rc.height - 1);

		//Desenha as linhas da grid (internas) na horizontal
		dc.DrawLine(p1x, p1y, p2x, p2y);
    }
}

void LabelAxis::SetAxisVisible(bool bVisible)
{
    m_visible = bVisible;
    FireAxisChanged();
}

void LabelAxis::Draw(wxDC &dc, wxRect rc)
{
    if (!m_visible)
        return;

	//Desenha o mini título de cada eixo
    //Calculate the axis' title position and draw the title.
    if (m_title.Length() != 0) 
    {
        wxSize titleExtent = dc.GetTextExtent(m_title);

        dc.SetFont(m_titleFont);
        dc.SetTextForeground(m_titleColour);

        if (IsVertical()) {
            wxCoord y;
            switch (m_titleLocation) {
                case wxTOP:
                    y = rc.y + titleExtent.x;
                    break;
                case wxCENTER:
                    y = rc.y + titleExtent.GetWidth() + (rc.GetHeight() - titleExtent.GetWidth()) / 2;
                    break;
                case wxBOTTOM:
                    y = rc.y + rc.height;
                    break;
                default:
                    // fallback to center
                    y = (rc.y + rc.height) / 2 + titleExtent.x / 2;
            }
            if (GetLocation() == AXIS_LEFT) {
                dc.DrawRotatedText(m_title, rc.x, y, 90);                    
                rc.x += titleExtent.y;
            } else {
                dc.DrawRotatedText(m_title, rc.x + rc.width - titleExtent.y, y, 90);                                    
            }            
            rc.width -= titleExtent.y;
        }
        else {
            wxCoord x;
            switch (m_titleLocation) {
                case wxLEFT:
                    x = rc.x;
                    break;
                case wxCENTER:
                    // PBFIX
                    x = rc.x + (rc.GetWidth() - titleExtent.GetWidth()) / 2;
                    // x = (rc.x + rc.width) / 2 - titleExtent.x / 2;
                    break;
                case wxRIGHT:
                    x = rc.x + rc.width - titleExtent.x;
                    break;
                default:
                    // fallback to center
                    x = rc.x + (rc.GetWidth() - titleExtent.GetWidth()) / 2;
            }

            if (GetLocation() == AXIS_TOP) {
                dc.DrawText(m_title, x, rc.y);
            } else {
                dc.DrawText(m_title, x, rc.y + rc.height - titleExtent.y);
                rc.SetBottom(rc.GetBottom() - titleExtent.y);                
            }
        }
    }
    
    // Draw the tick marks and labels.
    DrawLabels(dc, rc); //Desenha os números ao lado e os seus indicadores
    
    // Draw the border.
    DrawBorderLine(dc, rc); //Não faz nada
}

bool LabelAxis::HasLabels()
{
    return true;
}

