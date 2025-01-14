/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:37:39 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/31 20:48:08 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loop.h"

void	refresh_keyboard(t_ctx *ctx)
{
	t_vector4	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	v.w = 0;
	if (ctx->keyboard->key[12])
		matrice_rotation_z_from_world(&ctx->map_obj->matrice, TO_RAD(0.5));
	if (ctx->keyboard->key[14])
		matrice_rotation_z_from_world(&ctx->map_obj->matrice, -TO_RAD(0.5));
	v.z = (ctx->keyboard->key[13]) ? v.z - 1 : v.z;
	v.z = (ctx->keyboard->key[1]) ? v.z + 1 : v.z;
	v.x = (ctx->keyboard->key[2]) ? v.x - 1 : v.x;
	v.x = (ctx->keyboard->key[0]) ? v.x + 1 : v.x;
	v.y = (ctx->keyboard->key[256]) ? v.y - 1 : v.y;
	v.y = (ctx->keyboard->key[49]) ? v.y + 1 : v.y;
	if (ctx->keyboard->key[257])
		vector4_multiply(&v, 10);
	matrice_translation_from_world(&ctx->map_obj->matrice, &v);
	if (ctx->keyboard->key[53])
		close_fdf(ctx);
}

void	refresh_input_devices(t_ctx *ctx)
{
	int			delta_x;
	int			delta_y;

	if (ctx->mouse->button[4])
	{
		ctx->map_obj->mesh->matrice.m[10] *= 1.1;
		ctx->mouse->button[4] = 0;
	}
	if (ctx->mouse->button[5])
	{
		ctx->map_obj->mesh->matrice.m[10] *= 0.9;
		ctx->mouse->button[5] = 0;
	}
	if (ctx->mouse->button[1])
	{
		delta_x = ctx->mouse->last_x - ctx->mouse->x;
		delta_y = ctx->mouse->last_y - ctx->mouse->y;
		matrice_rotation_y_from_world(
				&ctx->map_obj->matrice, -TO_RAD(delta_x) / 5);
		matrice_rotation_x_from_world(
				&ctx->map_obj->matrice, -TO_RAD(delta_y) / 5);
		ctx->mouse->last_x = ctx->mouse->x;
		ctx->mouse->last_y = ctx->mouse->y;
	}
	refresh_keyboard(ctx);
}

int		loop(t_ctx *ctx)
{
	refresh_stats(ctx->stats);
	ft_bzero(ctx->screen->canevas->data,
		ctx->screen->canevas->width * ctx->screen->canevas->height * 4);
	refresh_input_devices(ctx);
	render(ctx);
	draw_hud(ctx);
	mlx_put_image_to_window(ctx->mlx,
		ctx->screen->win, ctx->screen->canevas->id, 0, 0);
	return (1);
}
