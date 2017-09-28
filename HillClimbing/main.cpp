#include <qwt_plot_curve.h>
#include <qwt_plot.h>
#include <qapplication.h>


#define PLOT_TITLE "Hill Climbing Algorithm"
#define FUNC_STRING "f(x) = sin(x/10)"

#define VALUE_COUNT 1000


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

	// insert data
    curve->setRawData(x, y, VALUE_COUNT);
    curve->attach(&plot);
    plot.show();
	
    return a.exec();
}
