all:
	mkdir -vp dest
	cd dest; cmake ..; make
clean:
	if [ -d dest ]; then rm -rf dest; fi
doc:
	fx-doc build doc dest/doc --no-pdf
doc-force:
	fx-doc build doc dest/doc --no-pdf --force
doc-serve:
	fx-doc serve dest/doc
.PHONY: all clean doc doc-serve
