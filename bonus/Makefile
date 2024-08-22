# Color variables
RED = \033[0;31m
GRN = \033[0;32m
YEL = \033[0;33m
BLU = \033[0;34m
MAG = \033[0;35m
CYN = \033[0;36m
WHT = \033[0;37m
RES = \033[0m

# Compiler-related variables
CC = cc
CFLAGS = -Werror -Wall -Wextra -g
LIBMLX_DIR = ./includes/minilibx-linux
LIBFLAGS = -lX11 -lXext -lm -lz -O3
VG = valgrind --leak-check=full --show-leak-kinds=all --suppressions=sup --track-origins=yes --log-file=leaks.log

# File-related variables
NAME = cub3D_bonus
LIBFT = ./includes/libft/libft.a
MINILIBX = $(LIBMLX_DIR)/libmlx.a
RM = rm -rf
SDIR := src
ODIR := obj

# Source files
SOURCES := cub3d_bonus.c\
			parser/mapValidator_bonus.c\
			parser/mapValidator2_bonus.c\
			parser/mapValidator3_bonus.c\
			parser/mapValidator4_bonus.c\
			parser/mapValidator5_bonus.c\
			parser/mapValidator6_bonus.c\
			parser/mapValidator7_bonus.c\
			parser/mapValidator8_bonus.c\
			parser/mapValidator9_bonus.c\
			parser/mapValidatorUtils_bonus.c\
			game/renders/renders_bonus.c\
			game/renders/minimap_bonus.c\
			game/renders/player_bonus.c\
			game/renders/bresenham_bonus.c\
			game/renders/sprite_bonus.c\
			game/renders/sprite_torch_bonus.c\
			game/renders/weapon_bonus.c\
			game/logic/dda_bonus.c\
			game/logic/dda_utils_bonus.c\
			game/utils/utils1_bonus.c\
			game/utils/utils2_bonus.c\
			game/handlers/close_handlers_bonus.c\
			game/handlers/keypress_handlers_bonus.c\
			game/handlers/game_handlers_bonus.c\
			game/handlers/mouse_handlers_bonus.c\
			game/handlers/movement_bonus.c\
			game/game_bonus.c\
			game/fps_bonus.c\
			game/shadow_bonus.c\
			errorHandler_bonus.c\
			freedom_bonus.c\
			init_bonus.c\

# Object files
OBJECTS := $(patsubst %.c,$(ODIR)/%.o,$(SOURCES))

TOTAL_FILES := $(words $(SOURCES))
COMPILED_FILES := $(shell if [ -d "$(ODIR)" ]; then find $(ODIR) -name "*.o" | wc -l; else echo 0; fi)

# Targets
all : ${NAME}

${NAME} : ${OBJECTS} $(LIBFT) $(MINILIBX)
	@${CC} ${CFLAGS} ${OBJECTS} -o ${NAME} $(LIBFT) $(MINILIBX) ${LIBFLAGS}
	@printf "$(GRN)➾ Compilation progress: $$(echo "$(shell find $(ODIR) -name "*.o" | wc -l) $(TOTAL_FILES)" | awk '{printf "%.2f", $$1/$$2 * 100}')%%$(RES)\r"
	@echo "\n$(GRN)➾ ${NAME} created$(RES)"
	@printf "\n"

$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@printf "$(GRN)➾ Compilation progress: $$(echo "$(shell find $(ODIR) -name "*.o" | wc -l) $(TOTAL_FILES)" | awk '{printf "%.2f", $$1/$$2 * 100}')%%$(RES)\r"

# Rest of your Makefile
$(ODIR):
	@mkdir -p $@

$(LIBFT) :
	@cd ./includes/libft/ && make bonus -s
	@echo "libft.a created"

$(MINILIBX) :
	@cd ./includes/minilibx-linux/ && make -s
	@echo "libmlx.a created"

clean :
	@${RM} ${OBJECTS}
	@${RM} ${ODIR}

fclean : clean
	@${RM} ${NAME}
	@echo "${RED}➾ ${NAME} deleted${RES}"

re : fclean all

debug: all sup_file
	@echo "$(GREEN)$(NAME) compiled in debug mode!$(DEF_COLOR)"

leaks: ./$(NAME)
	@if [ -f leaks.log ]; then mv leaks.log leaks-old.log; fi
	$(VG) ./$(NAME) maps/example.cub

gdb: re
	gdb --tui $(NAME)

.PHONY: all clean fclean re gdb leaks sup_file debug

define SUP_BODY
{
   mlx_mouse_hide
   Memcheck:Leak
   ...
   fun:mlx_mouse_hide
}
{
	leak XrmGetStringDatabase
	Memcheck:Leak
	...
	fun:XrmGetStringDatabase
}
{
	leak _dl_open
	Memcheck:Leak
	...
	fun:_dl_open
}
{
	leak _XrmInitParseInfo
	Memcheck:Leak
	...
	fun:_XrmInitParseInfo
}
endef

sup_file:
	$(file > sup,$(SUP_BODY))
	@echo "$(MAG)Created suppression file to use with valgrind --suppressions=sup$(RES)"