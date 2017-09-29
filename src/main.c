/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 10:34:46 by evanheum          #+#    #+#             */
/*   Updated: 2017/09/29 11:14:37 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    match_fract_ol(char *s, t_env *env)
{
    if (!(ft_strcmp(s, "Julia")))
    {
        env->f = &Julia;
        open_mlx(env, s);
    }
    else if(!(ft_strcmp(s, "Mandelbrot")))
    {
        env->f = &Mandelbrot;
        open_mlx(env, s);
    }
    else if(!(ft_strcmp(s, "Fan")))
    {
        env->f = &Fan;
        open_mlx(env, s);
    }
    else if (!(ft_strcmp(s, "Lemon")))
    {
        env->f = &Lemon;
        open_mlx(env, s);
    }
    else
    {
        ft_printf("Invalid Fract_ol\n");
        return ;
    }
}

void        open_mlx(t_env *env, char *s)
{
    env->mlx = mlx_init();
    env->img = mlx_new_image(env->mlx, W_W, W_H);
    env->pixels = (int*)mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->endian);
    env->win = mlx_new_window(env->mlx, env->w_w, env->w_h, s);
    draw_pixel(env);
    mlx_hook(env->win, 6, 0, mouse_pos, env);
    mlx_mouse_hook(env->win, zoom_img, env);
    mlx_hook(env->win, 2, 0, key_master, env);
    mlx_loop(env->mlx);
}
void        reset(t_env *env)
{
    // env->ja = 0.30176;
    // env->jb = 0.3842;
    env->x0 = 0;
    env->y0 = 0;
    env->trans_x = 0;
    env->trans_y = 0;
    env->zoom = 1;
}
t_env       *init_env(void)
{
    t_env   *env;
    env = (t_env*)malloc(sizeof(t_env));
    env->mlx = NULL;
    env->win = NULL;
    env->w_w = 1000;
    env->w_h = 1000;
    env->img = NULL;
    env->pixels = NULL;
    env->bpp = 4;
    env->sl = 0;
    env->endian = 0;
    env->f = 0;
    env->maxiteration = 100;
    env->color = 5;
    env->ja = 0.30176;
    env->jb = 0.3842;
    env->x0 = 0;
    env->y0 = 0;
    env->trans_x = 0;
    env->trans_y = 0;
    env->zoom = 1;
    env->lock = 0;
    return (env);
}



int     main(int ac, char **av)
{
    t_env   *env;
    int c;

    c = ac;
    if (ac == 2)
    {
        env = init_env();
        match_fract_ol(av[1], env);
    }
    else
    {
        ft_printf("Invalid input\nExpects:\n ./fractol [fract_ol]\n FRACT_OL'S\n");
        ft_printf(" 1: Julia\n 2:Manelbrot\n 3:Fan\n 4:Lemon\n");
        ft_printf("To change the color use 'Q' and 'E' to reset color 'R'\n");
        ft_printf("To move the fract'ol around use 'A' 'W' 'S' 'D'\n");
        ft_printf("reset back to center 'tab' zoom in and out use mousewheel\n");
        ft_printf(" Use 'T' to lock the fract'ol in place and 'Y' to unlock\n");
        return (-1);
    }
}
