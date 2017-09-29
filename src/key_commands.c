/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:49:10 by evanheum          #+#    #+#             */
/*   Updated: 2017/09/29 11:38:28 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int     key_master(int key, t_env *env)
{
    if (key == 17)
        env->lock = 1;
    if (key == 16)
        env->lock = 0;
    if (key == 48)
        reset(env);
    if (key == 53)
            exit(0);
    if (((key >= 0 && key <= 2) || key == 13) && env->lock == 0)
    {
        if (key == 48)
            reset(env);
        else if (key == 13)
            env->trans_y += 5;
        else if (key == 1)
            env->trans_y -= 5;
        else if (key == 0)
            env->trans_x += 5;
        else if (key == 2)
            env->trans_x -= 5;
    }
    if (key == 12 || key == 14 || key == 15)
            key_color(key, env);
    draw_pixel(env);
    return (0);
}

int     mouse_pos(int x, int y, t_env *env)
{
    if ((x == env->ja && y == env->jb) || env->lock == 1)
        return (0);
    env->ja = ((((double)x - W_W) / (W_W / 2)) + 1);
    env->jb = ((((double)y - W_H) / (W_H / 2)) + 1);
    draw_pixel(env);
    return (0);
}

int     zoom_img(int key, int x, int y, t_env *env)
{
    if (key == 4 || key == 5)
    {
        env->x0 += (x - env->trans_x) / ((W_W / 4) * env->zoom);
        env->y0 += (y - env->trans_y) / ((W_H / 4) * env->zoom);
        env->zoom *= ((key == 4) ? ZO_OM : 1 / ZO_OM);
        env->trans_x = x;
        env->trans_y = y;
        draw_pixel(env);
    }
    return (0);
}

void    key_color(int key, t_env *env)
{
    if (key == 12 && env->color < 9999999)
        env->color *= 5;
    else if (key == 14 && env->color > 5)
        env->color /= 5;
    else if (key == 15)
        env->color = 5;
}