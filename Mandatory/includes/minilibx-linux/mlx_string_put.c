/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_string_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:12:06 by ruiolive          #+#    #+#             */
/*   Updated: 2024/07/30 11:12:07 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** mlx_string_put.c for MiniLibX in 
 ** 
 ** Made by Charlie Root
 ** Login   <ol@epitech.net>
 ** 
 ** Started on  Mon Jul 31 19:01:33 2000 Charlie Root
** Last update Tue Sep 25 17:11:47 2001 Charlie Root
 */


#include	"mlx_int.h"



int		mlx_string_put(t_xvar *xvar,t_win_list *win,
			       int x,int y,int color,char *string)
{
   XGCValues	xgcv;
   
   xgcv.foreground = mlx_int_get_good_color(xvar,color);
   XChangeGC(xvar->display,win->gc,GCForeground,&xgcv);
   XDrawString(xvar->display,win->window,win->gc,x,y,string,strlen(string));
   if (xvar->do_flush)
     XFlush(xvar->display);
}
