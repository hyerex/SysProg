PACKAGES=lib bin
.PHONY: all clean
all clean:
	for p in $(PACKAGES); do \
		(cd $$p && $(MAKE) $@); \
	done
#Makefiles werden rekursiv aufgerufen

# Was könnte man in Ihren Makefiles alles weglassen, wenn man auf die make-Option -R verzichten würde?
