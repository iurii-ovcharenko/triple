BUILD_DIR	:= $(shell pwd)
TOP_DIR		:= $(BUILD_DIR)/..
SRC_DIR		= $(TOP_DIR)/src
INC_DIR		= $(TOP_DIR)/include

PROG		= prog
$(PROG)_SRCS	= $(wildcard $(SRC_DIR)/*.c)
$(PROG)_INCS	= $(wildcard $(INC_DIR)/*.h)
$(PROG)_OBJS	= $(foreach f,$($(PROG)_SRCS),$(f:.c=.o))


printv	= $(info "$(1)=$($(1))")

CC	= gcc
LD	= gcc

CFLAGS	= -Wall -Wextra
CFLAGS	+= $(foreach f,$(INC_DIR),-I$(f))
CFLAGS	+= -DFORCEMAJOR=1

$(call printv,BUILD_DIR)
$(call printv,TOP_DIR)
$(call printv,SRC_DIR)
$(call printv,INC_DIR)
$(call printv,$(PROG)_SRCS)
$(call printv,$(PROG)_OBJS)

all: $(PROG)

$(PROG): $($(PROG)_OBJS)
	$(LD) -o $(@) $($(PROG)_OBJS)

%.o: %.c $($(PROG)_INCS)
	$(CC) -c -o $@ $(CFLAGS) $<

.PHONY: clean

clean:
	rm -f $(PROG)
	rm -f $(SRC_DIR)/*.o
