/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 10:34:46 by evanheum          #+#    #+#             */
/*   Updated: 2017/09/29 10:57:29 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw_pixel(t_env *env)
{
    int x;
    int y;
    int i;

    i = 0;
    y = 0;
    while (y < W_H)
    {
        x = 0;
        while (x < W_W)
        {
            i = env->f(env, x - (W_W / 2), y - (W_H / 2));
            env->pixels[x + ( y * W_H)] = ((i < env->maxiteration) ? i * env->color : 0);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
int     Mandelbrot(t_env *env, int x, int y)
{
    int i;
    double tab[6];

    tab[0] = ((double)x - env->trans_x) / ((W_W / 4) * env->zoom) + env->x0;
    tab[1] = ((double)y - env->trans_y) / ((W_H / 4) * env->zoom) + env->y0;
    tab[2] = tab[0];
    tab[3] = tab[1];
    i = -1;
    while (++i < env->maxiteration && (tab[0]*tab[0]) + (tab[1]*tab[1]) <= 16)
    {
        tab[4] = (tab[0] * tab[0]) - (tab[1] * tab[1]);
        tab[5] = 2 * tab[0] * tab[1];
        tab[0] = tab[4] + tab[2];
        tab[1] = tab[5] + tab[3];
    }
    return (i);
}

int     Julia(t_env *env, int x, int y)
{
    int i;
    double aa;
    double bb;
    double a;
    double b;

    a = ((double)x - env->trans_x) / ((W_W / 4) * env->zoom) + env->x0;
    b = ((double)y - env->trans_y) / ((W_H / 4) * env->zoom) + env->y0;
    i = -1;
    while (++i < env->maxiteration && (a*a) + (b*b) <= 16)
    {
        aa = (a * a) - (b * b);
        bb = 2 * a * b;
        a = aa - env->ja;
        b = bb + env->jb;
    }
    return (i);      
}

int     Fan(t_env *env, int x, int y)
{
    int i;
    double aa;
    double bb;
    double a;
    double b;

    a = ((double)x - env->trans_x) / ((W_W / 4) * env->zoom) + env->x0;
    b = ((double)y - env->trans_y) / ((W_H / 4) * env->zoom) + env->y0;
    i = -1;
    while (++i < env->maxiteration && (a*a) + (b*b) <= 16)
    {
        aa = (a * a) - (b * b);
        bb = 2 * a * b;
        a = aa - env->ja/bb;
        b = bb + env->jb/aa;
    }
    return (i);
}

int     Lemon(t_env *env, int x, int y)
{
    int i;
    double aa;
    double bb;
    double a;
    double b;

    a = ((double)x - env->trans_x) / ((W_W / 4) * env->zoom) + env->x0;
    b = ((double)y - env->trans_y) / ((W_H / 4) * env->zoom) + env->y0;
    i = -1;
    while (++i < env->maxiteration && (a*a) + (b*b) <= 16)
    {
        aa = (a * a * a) + (b * b * b);
        bb = 2 * a * b;
        a = aa - env->ja;
        b = bb + env->jb;
    }
    return (i);      
}