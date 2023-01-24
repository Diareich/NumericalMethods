#include "MainForm.h"
#include "LagrangesInterpolation.h"
#include "NewtonInterpolation.h"
#include "FiniteDifferenceInterpolation.h"
#include "InterpolationMultipleNodes.h"

#include <math.h>
#include <algorithm>

namespace NumericalMethods
{
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing::Drawing2D;

    bool comparePoints(const point& left, const point& right)
    {
        return left.x < right.x;
    }

    Void MainForm::render(Graphics^ graphics)
    {
        int n = getPointsNumber();
        vector<point> points;
        for (int i = 0; i < n; i++)
        {
            point p;
            try
            {
                p = getPoint(i);
                points.push_back(p);
            }
            catch (...)
            {
            }
        }

        sort(points.begin(), points.end(), comparePoints);
        for (int i = (int)points.size() - 1; i >= 0; i--)
        {
            double x = points[i].x;
            for (int j = i - 1; j >= 0; j--)
            {
                if (x == points[j].x)
                {
                    points.erase(points.begin() + j);
                    i--;
                }
            }
        }

        if (checkBoxAutoScale->Checked)
        {
            startX = int::MaxValue;
            startY = int::MaxValue;
            endX = int::MinValue;
            endY = int::MinValue;
            for (int i = 0; i < points.size(); i++)
            {
                if (points[i].x > endX)
                    endX = (int)points[i].x;
                if (points[i].y > endY)
                    endY = (int)points[i].y;
                if (points[i].x < startX)
                    startX = (int)points[i].x;
                if (points[i].y < startY)
                    startY = (int)points[i].y;
            }
            startX -= 1;
            endX += 1;
            startY -= 1;
            endY += 1;
        }

        if (startX < endX&& startY < endY)
        {
            auto centerX = (endX + startX) / 2;
            auto centerY = (endY + startY) / 2;

            graphics->SmoothingMode = SmoothingMode::HighQuality;
            graphics->Clear(Color::White);
            float graphWidth = (float)panelGraph->ClientSize.Width;
            float graphHeight = (float)panelGraph->ClientSize.Height;
            auto grapCenterX = graphWidth / 2;
            auto grapCenterY = graphHeight / 2;
            float width = (float)(endX - startX);
            float height = (float)(endY - startY);
            float size = (float)(width > height ? width * 1.5 : height * 1.5);
            float graphSize = (float)(graphWidth > graphHeight ? graphWidth : graphHeight);
            float cellSize = graphSize / size;

            if (checkBoxCells->Checked)
            {
                float drawCellSize = cellSize;
                while (drawCellSize < 20)
                    drawCellSize *= 2;
                while (drawCellSize > 100)
                    drawCellSize /= 2;
                auto numbersFont = gcnew System::Drawing::Font("Segoe UI", (float)pow(drawCellSize, 0.25) * 3.5f, FontStyle::Bold);
                float zeroX = grapCenterX + (0 - centerX) * cellSize;
                float zeroY = grapCenterY - (0 - centerY) * cellSize;
                graphics->DrawLine(cooldinatePen, zeroX, 0.f, zeroX, graphHeight);
                graphics->DrawLine(cooldinatePen, 0.f, zeroY, graphWidth, zeroY);

                if (checkBoxNumbers->Checked)
                    graphics->DrawString("0", numbersFont, numbersBrush, RectangleF(zeroX + 2,
                        max(min(graphHeight - drawCellSize / 3.0f, zeroY + 1.0f), 1.0f), drawCellSize, drawCellSize));

                for (float x = 1;; x++)
                {
                    float drawingX = zeroX + x * drawCellSize;
                    graphics->DrawLine(Pens::Gray, drawingX, 0.f, drawingX, graphHeight);
                    if (drawingX > graphWidth)
                        break;
                    if (checkBoxNumbers->Checked)
                        graphics->DrawString((x / cellSize * drawCellSize).ToString(), numbersFont, numbersBrush, RectangleF(drawingX + 2,
                            max(min(graphHeight - drawCellSize / 3.0f, zeroY + 1.0f), 1.0f), drawCellSize * 2, drawCellSize));
                }
                for (float x = -1;; x--)
                {
                    float drawingX = zeroX + x * drawCellSize;
                    graphics->DrawLine(Pens::Gray, drawingX, 0.f, drawingX, graphHeight);
                    if (drawingX < 0)
                        break;
                    if (checkBoxNumbers->Checked)
                        graphics->DrawString((x / cellSize * drawCellSize).ToString(), numbersFont, numbersBrush, RectangleF(drawingX + 2,
                            max(min(graphHeight - drawCellSize / 3.0f, zeroY + 1.0f), 1.0f), drawCellSize * 2, drawCellSize));
                }
                for (float y = 1;; y++)
                {
                    float drawingY = zeroY - y * drawCellSize;
                    graphics->DrawLine(Pens::Gray, 0.f, drawingY, graphWidth, drawingY);
                    if (drawingY < 0)
                        break;
                    if (checkBoxNumbers->Checked)
                        graphics->DrawString((y / cellSize * drawCellSize).ToString(), numbersFont, numbersBrush, RectangleF(
                            max(min(graphWidth - drawCellSize, zeroX + 2.0f), 1.0f), drawingY + 1,
                            drawCellSize * 2, drawCellSize));
                }
                for (float y = -1;; y--)
                {
                    float drawingY = zeroY - y * drawCellSize;
                    graphics->DrawLine(Pens::Gray, 0.f, drawingY, graphWidth, drawingY);
                    if (drawingY > graphHeight)
                        break;
                    if (checkBoxNumbers->Checked)
                        graphics->DrawString((y / cellSize * drawCellSize).ToString(), numbersFont, numbersBrush, RectangleF(
                            max(min(graphWidth - drawCellSize, zeroX + 2.0f), 1.0f), drawingY + 1,
                            drawCellSize * 2, drawCellSize));
                }
            }

            double step = 5.0;
            double drawingX = 0.0;
            double x = (drawingX - grapCenterX) / cellSize + centerX;
            double y;
            if (lagrangesInterpolateToolStripMenuItem->Checked)
                y = lagrangesInterpolate(points, x);
            else if (finiteDifferenceInterpolationToolStripMenuItem->Checked)
                y = finiteDifferenceInterpolation(points, x);
            else if (newtonInterpolationToolStripMenuItem->Checked)
                y = newtonInterpolation(points, x);
            else if (interpolationMultipleNodesToolStripMenuItem->Checked)
                y = interpolationMultipleNodes(points, x);
            double drawingY = grapCenterY - (y - centerY) * cellSize;
            double previousX = drawingX;
            double previousY = drawingY;
            try
            {
                for (drawingX = step; drawingX <= graphWidth + step; drawingX += step)
                {
                    x = x = (drawingX - grapCenterX) / cellSize + centerX;
                    if (lagrangesInterpolateToolStripMenuItem->Checked)
                        y = lagrangesInterpolate(points, x);
                    else if (finiteDifferenceInterpolationToolStripMenuItem->Checked)
                        y = finiteDifferenceInterpolation(points, x);
                    else if (newtonInterpolationToolStripMenuItem->Checked)
                        y = newtonInterpolation(points, x);
                    else if (interpolationMultipleNodesToolStripMenuItem->Checked)
                        y = interpolationMultipleNodes(points, x);
                   
                    drawingY = grapCenterY - (y - centerY) * cellSize;
                    if (!double::IsNaN(y) && !double::IsInfinity(y) && !double::IsNaN(previousY) && !double::IsInfinity(previousY))
                        graphics->DrawLine(linePen, (float)previousX, (float)previousY, (float)drawingX, (float)drawingY);
                    previousX = drawingX;
                    previousY = drawingY;
                }
            }
            catch (...)
            {
            }

            if (checkBoxPoints->Checked)
            {
                for (int i = 0; i < points.size(); i++)
                {
                    if (!double::IsNaN(points[i].y) && !double::IsInfinity(points[i].y))
                    {
                        double drawingX = grapCenterX + (points[i].x - centerX) * cellSize;
                        double drawingY = grapCenterY - (points[i].y - centerY) * cellSize;
                        graphics->FillEllipse(pointBrush, (float)drawingX - 4.0f, (float)drawingY - 4.0f, 8.0f, 8.0f);
                    }
                }
            }
        }  
    }

    Void MainForm::panelGraph_Paint(Object^ sender, PaintEventArgs^ e)
    {
        render(e->Graphics);
    }

    Void MainForm::panelGraph_Resize(Object^ sender, EventArgs^ e)
    {
        panelGraph->Invalidate();
    }

    Void MainForm::dataGridView_CellEndEdit(Object^ sender, DataGridViewCellEventArgs^ e)
    {
        panelGraph->Invalidate();
    }

    Void MainForm::buttonAddPoint_Click(Object^ sender, EventArgs^ e)
    {
        int n = getPointsNumber() - 1;
        point p = getPoint(n);
        addColumn(p.x + 1.0, p.y);
        panelGraph->Invalidate();
    }

    Void MainForm::buttonRemovePoint_Click(Object^ sender, EventArgs^ e)
    {
        if (dataGridView->ColumnCount > 2)
        {
            dataGridView->Columns->RemoveAt(dataGridView->ColumnCount - 1);
            panelGraph->Invalidate();
        }
    }

    System::Void MainForm::numericUpDowns_ValueChanged(System::Object^ sender, System::EventArgs^ e)
    {
        startX = (int)numericUpDownStartX->Value;
        endX = (int)numericUpDownEndX->Value;
        startY = (int)numericUpDownStartY->Value;
        endY = (int)numericUpDownEndY->Value;
        panelGraph->Invalidate();
    }

    System::Void MainForm::checkBoxAutoScale_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
    {
        numericUpDownStartX->Enabled = !checkBoxAutoScale->Checked;
        numericUpDownEndX->Enabled = !checkBoxAutoScale->Checked;
        numericUpDownStartY->Enabled = !checkBoxAutoScale->Checked;
        numericUpDownEndY->Enabled = !checkBoxAutoScale->Checked;
        if (!checkBoxAutoScale->Checked)
            numericUpDowns_ValueChanged(this, EventArgs::Empty);
        else
            panelGraph->Invalidate();
    }

    System::Void MainForm::checkBoxCells_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
    {
        panelGraph->Invalidate();
    }

    System::Void MainForm::checkBoxNumbers_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
    {
        panelGraph->Invalidate();
    }

    System::Void MainForm::lagrangesInterpolateToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        lagrangesInterpolateToolStripMenuItem->Checked = true;
        finiteDifferenceInterpolationToolStripMenuItem->Checked = false;
        newtonInterpolationToolStripMenuItem->Checked = false;
        interpolationMultipleNodesToolStripMenuItem->Checked = false;
        panelGraph->Invalidate();
    }

    Void MainForm::newtonInterpolationToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
    {
        lagrangesInterpolateToolStripMenuItem->Checked = false;
        finiteDifferenceInterpolationToolStripMenuItem->Checked = false;
        newtonInterpolationToolStripMenuItem->Checked = true;
        interpolationMultipleNodesToolStripMenuItem->Checked = false;
        panelGraph->Invalidate();
    }

    System::Void MainForm::finiteDifferenceInterpolationToolStripMenuItem_Click(Object^ sender, EventArgs^ e)
    {
        lagrangesInterpolateToolStripMenuItem->Checked = false;
        finiteDifferenceInterpolationToolStripMenuItem->Checked = true;
        newtonInterpolationToolStripMenuItem->Checked = false;
        interpolationMultipleNodesToolStripMenuItem->Checked = false;
        panelGraph->Invalidate();
    }

    System::Void MainForm::interpolationMultipleNodesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        lagrangesInterpolateToolStripMenuItem->Checked = false;
        finiteDifferenceInterpolationToolStripMenuItem->Checked = false;
        newtonInterpolationToolStripMenuItem->Checked = false;
        interpolationMultipleNodesToolStripMenuItem->Checked = true;
        panelGraph->Invalidate();
    }

    System::Void MainForm::saveGraphToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        auto dialog = gcnew SaveFileDialog();
        dialog->Filter = "BMP Изображение (*.bmp)|*.bmp|PNG Изображение (*.png)|*.png|JPG Изображение (*.jpg)|*.jpg";
        dialog->FileName = "График";
        if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            auto image = gcnew Bitmap(panelGraph->ClientSize.Width, panelGraph->ClientSize.Height);
            auto grpaphics = Graphics::FromImage(image);
            render(grpaphics);
            image->Save(dialog->FileName);
        }
    }

    int MainForm::getPointsNumber()
    {
        return dataGridView->ColumnCount;
    }

    point MainForm::getPoint(int n)
    {
        point p;
        if (dataGridView->Rows[0]->Cells[n]->Value == nullptr)
            dataGridView->Rows[0]->Cells[n]->Value = "0";
        if (dataGridView->Rows[1]->Cells[n]->Value == nullptr)
            dataGridView->Rows[1]->Cells[n]->Value = "0";
        if (!double::TryParse(dataGridView->Rows[0]->Cells[n]->Value->ToString()->Replace(".", ","), p.x) || double::IsNaN(p.x) && double::IsInfinity(p.x))
            throw "Not double!";
        if (!double::TryParse(dataGridView->Rows[1]->Cells[n]->Value->ToString()->Replace(".", ","), p.y) || double::IsNaN(p.y) && double::IsInfinity(p.y))
            throw "Not double!";
        return p;
    }

    void MainForm::addColumn(double x, double y)
    {
        auto newColumnt = gcnew DataGridViewTextBoxColumn();
        newColumnt->AutoSizeMode = DataGridViewAutoSizeColumnMode::AllCells;
        dataGridView->Columns->Add(newColumnt);
        dataGridView->Rows[0]->Cells[dataGridView->ColumnCount - 1]->Value = x.ToString("0.###");
        dataGridView->Rows[1]->Cells[dataGridView->ColumnCount - 1]->Value = y.ToString("0.###");
    }

    Void MainForm::checkBoxPoints_CheckedChanged(Object^ sender, EventArgs^ e)
    {
        panelGraph->Invalidate();
    }

    System::Void MainForm::fxX3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        int columnCount = dataGridView->ColumnCount;
        for (double x = -2.0f; x <= 2.0; x++)
        {
            double y = pow(x, 3);
            addColumn(x, y);
        }
        for (int i = 0; i < columnCount; i++)
            dataGridView->Columns->RemoveAt(0);
        panelGraph->Invalidate();
    }

    System::Void MainForm::fxX2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        int columnCount = dataGridView->ColumnCount;
        for (double x = -2.0f; x <= 2.0; x++)
        {
            double y = pow(x, 2);
            addColumn(x, y);
        }
        for (int i = 0; i < columnCount; i++)
            dataGridView->Columns->RemoveAt(0);
        panelGraph->Invalidate();
    }

    System::Void MainForm::fxLogxToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        int columnCount = dataGridView->ColumnCount;
        for (double x = 0.01f; x <= 7.01; x++)
        {
            double y = log(x);
            addColumn(x, y);
        }
        for (int i = 0; i < columnCount; i++)
            dataGridView->Columns->RemoveAt(0);
        panelGraph->Invalidate();
    }

    System::Void MainForm::fx2xToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        int columnCount = dataGridView->ColumnCount;
        for (double x = -2.0f; x <= 2.0; x++)
        {
            double y = 2 * x;
            addColumn(x, y);
            dataGridView->Columns->RemoveAt(0);
        }
        for (int i = 0; i < columnCount; i++)
        panelGraph->Invalidate();
    }

    System::Void MainForm::fxSqrtxToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        int columnCount = dataGridView->ColumnCount;
        for (double x = 0.0; x <= 5.0; x++)
        {
            double y = sqrt(x);
            addColumn(x, y);
        }
        for (int i = 0; i < columnCount; i++)
            dataGridView->Columns->RemoveAt(0);
        panelGraph->Invalidate();
    }
}
