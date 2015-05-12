VERSION=2.0.1
ARCHIVE_URL=https://github.com/phalcon/cphalcon/archive/phalcon-v$(VERSION).tar.gz
ARCHIVE_FILE=php5-phalcon_$(VERSION).orig.tar.gz

default: clean download

clean:
	@rm -f ../$(ARCHIVE_FILE)
	@rm -fr ./phalcon

download:
	@wget $(ARCHIVE_URL) -O ../$(ARCHIVE_FILE)
	@mkdir ./phalcon
	@tar xfz ../$(ARCHIVE_FILE) -C ./phalcon --strip-components=1
