#include <qwt_plot_curve.h>
#include <qwt_plot.h>
#include <qapplication.h>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    double x[VALUE_COUNT];
    double y[VALUE_COUNT];

    for (int i = 0; i < VALUE_COUNT; ++i) {
        x[i] =  i / 10.0;
        y[i] = sin(x[i]);
    }

    QwtPlot plot;
    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setRawData(x, y, 101);
    curve->attach(&plot);
    plot.show();
	
    return a.exec();
}
