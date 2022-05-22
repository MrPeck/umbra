all:
	$(MAKE) -C hermes
	$(MAKE) -C nyx

clean:
	$(MAKE) -C hermes clean
	$(MAKE) -C nyx clean