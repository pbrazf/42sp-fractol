#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h> // ESC

# define WIDTH 800
# define HEIGHT 800

// Map pixel to complex
typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
}	t_fractal_type;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_view
{
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	zoom;
	double	offset_x;
	double	offset_y;
}	t_view;

typedef struct s_fractal
{
	t_fractal_type	type;
	int				max_iter;
	t_complex		julia_k;	
} t_fractal;

typedef struct s_app
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_view		view;
	t_fractal	fractal;
}	t_app;

/* utils */
int	exit_error();
int	ft_strcmp(char *str1, char *str2);

/* parsing */
int	validate_args(int argc, char **argv, t_app *app);

/* math */
t_complex	complex_square(t_complex z);
t_complex	complex_add(t_complex a, t_complex b);
void		app_set_defaults(t_app *app);
double		complex_abs2(t_complex z);

/* mapping */
t_complex	pixel_to_complex(int x, int y, t_app *app);

/* fractals */
int			mandelbrot_iter(t_complex c, int max_iter);
int			julia_iter(t_complex z0, t_complex k, int max_iter);

/* mlx */
int		app_init_mlx(t_app *app);
void	app_destroy(t_app *app);

/* img */
void	put_pixel(t_img *img, int x, int y, int color);
int		color_from_iter(int i, int max);

/* render */
void		render(t_app *app);
// int		present(t_app *app);

/* events */
int		init_hooks(t_app *app);

/* zoom */
int			on_mouse(int button, int x, int y, t_app *app);
void		apply_zoom(t_app *app, t_complex center, double factor);
int			redraw(t_app *app);
void		apply_zoom(t_app *app, t_complex center, double factor);

#endif
