XCTOOL=xctool
SCHEME=M13OrderedDictionary
XCTOOL_FLAGS=-scheme $(SCHEME)

test: check-xctool clean
	$(XCTOOL) $(XCTOOL_FLAGS) build-tests 1>/dev/null 2>&1
	$(XCTOOL) $(XCTOOL_FLAGS) run-tests

clean: check-xctool
	$(XCTOOL) $(XCTOOL_FLAGS) clean 1>/dev/null 2>&1

check-xctool:
	which $(XCTOOL) 1>/dev/null 2>&1 || \
	(echo "\n\n>>> Please install xctool first. (https://github.com/facebook/xctool)\n" && exit 1)
