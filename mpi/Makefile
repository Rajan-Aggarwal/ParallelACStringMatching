TARGET   = a.out

CC       = mpicc
CFLAGS   = -std=c99 -Wall -I.

LINKER   = mpicc -o
LFLAGS   = -Wall -I. -lm

INCLDIR  = include
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
DIRS     = bin obj

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(INCLDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@$(rm) $(BINDIR)/$(TARGET)

$(shell mkdir -p $(DIRS))