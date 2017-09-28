#include <qwt_plot_curve.h>
#include <qwt_scale_engine.h>
#include <qwt_plot.h>
#include <qapplication.h>


#define PLOT_TITLE "Hill Climbing Algorithm"
#define FUNC_STRING "f(x) = sin(x/10)"

#define VALUE_COUNT 1000

/**
 * Useful Links
 * http://www.richelbilderbeek.nl/CppLinkErrorUndefinedReferenceToQwtPlot.htm
 * https://de.wikibooks.org/wiki/Qt_f%C3%BCr_C%2B%2B-Anf%C3%A4nger:_Qwt_nutzen
 * http://www.aboutlinux.info/2006/01/creating-and-compiling-qt-projects-on.html
 *
 * http://norvig.com/ngrams/ch14.pdf
 * https://en.wikipedia.org/wiki/Simulated_annealing
 * https://amitksaha.wordpress.com/2010/03/14/hill-climbing-a-simple-optimization-method/
 * https://www.quora.com/How-can-the-hill-climbing-algorithm-be-implemented-in-a-programming-language
 *
 * QWT DOCU:
 * http://qwt.sourceforge.net/class_qwt_scale_engine.html
 */

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
	
	// configure plot
	plot.setAxisTitle(QwtPlot::yLeft, FUNC_STRING);
	plot.setAxisTitle(QwtPlot::xBottom, "x");
	plot.setTitle(PLOT_TITLE);
	plot.axisScaleEngine(QwtPlot::xBottom)->setAttribute(QwtScaleEngine::Floating,true);
	plot.setAxisScale(QwtPlot::xBottom, 0, VALUE_COUNT/10, 1);
	plot.resize(200, 200);

	// show plot
    plot.show();

    return a.exec();
}
