TARGET?=report
LATEX_BUILD_CMD=pdflatex -interaction=nonstopmode

default: build

clean:
	rm -f *.acn *.acr *.alg *.aux *.bbl *.blg *.dvi *.glg *.glo *.gls *.ist *.lof *.log *.lol *.lot *.out *.pdf *.toc
build: 
	$(LATEX_BUILD_CMD) $(TARGET).tex
	bibtex ${TARGET} || true
	$(LATEX_BUILD_CMD) $(TARGET).tex
#	makeindex -s $(TARGET).ist -t $(TARGET).glg -o $(TARGET).gls $(TARGET).glo
#	makeindex -s $(TARGET).ist -t $(TARGET).alg -o $(TARGET).acr $(TARGET).acn
	@echo -------------------------------------------------------
	@echo Final run.
	$(LATEX_BUILD_CMD) $(TARGET).tex | grep 'Warning\|pages'

