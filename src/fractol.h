/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 10:31:41 by evanheum          #+#    #+#             */
/*   Updated: 2017/09/29 10:44:47 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/megalibft.h"
# include "../libmlx/mlx.h"
# define W_W 1000
# define W_H 1000
# define ZO_OM 1.05

typedef struct      s_env
{
    void            *mlx;
    void            *win;
    void            *img;
    int             *pixels;
    int             w_w;
    int             w_h;
    int             bpp;
    int             sl;
    int             endian;
    int             maxiteration;
    double             color;
    double          ja;
    double          jb;
    double           zoom;
    int             y0;
    int             x0;
    int             trans_x;
    int             trans_y;
    int             lock;
    int             (*f)(struct s_env *env, int x, int y);
}                   t_env;
/*
** ---------------------- fractol.c ---------------------
*/
void    draw_pixel(t_env *env);
int     Mandelbrot(t_env *env, int x, int y);
int     Julia(t_env *env, int x, int y);
int     Fan(t_env *env, int x, int y);
int     Lemon(t_env *env, int x, int y);
/*
** ----------------------  main.c  ----------------------
*/
t_env   *init_env(void);
void    match_fract_ol(char *s, t_env *env);
void    open_mlx(t_env *env, char *s);
void        reset(t_env *env);
/*
** ------------------- keycommands.c --------------------
*/
int     mouse_pos(int x, int y, t_env *env);
int     zoom_img(int key, int x, int y, t_env *env);
int     key_master(int key, t_env *env);
void    key_color(int key, t_env *env);
#endif