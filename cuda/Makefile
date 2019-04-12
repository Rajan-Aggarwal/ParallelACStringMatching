TARGET   = a.out

CC       = nvcc
CFLAGS   = -std=c99 -Wall -I.
CUDA_CFLAGS = $(foreach option, $(CFLAGS), --compiler-options $(option))

LINKER   = nvcc -o
LFLAGS   = -Wall -I. -lm
CUDA_LFLAGS = $(foreach option, $(LFLAGS), --compiler-options $(option))

INCLDIR  = include
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
DIRS     = bin obj

SOURCES  := $(wildcard $(SRCDIR)/*.cu) 
INCLUDES := $(wildcard $(INCLDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cu=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(CUDA_LFLAGS) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cu
	@$(CC) $(CUDA_FLAGS) -c $< -o $@

.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@$(rm) $(BINDIR)/$(TARGET)

$(shell mkdir -p $(DIRS))
