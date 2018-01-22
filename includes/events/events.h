/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gelambin <gelambin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:55:07 by gelambin          #+#    #+#             */
/*   Updated: 2018/01/18 09:31:52 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H
# include "mlx.h"
# include "ctx.h"
# include "x11_events.h"
# include "keyboard.h"
# include "mouse.h"
# include "loop.h"

int		hooks(t_ctx *ctx);

#endif