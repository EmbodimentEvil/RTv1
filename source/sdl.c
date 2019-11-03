/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:25:10 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/03 20:23:52 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

double		vec_dot(t_vector a, t_vector b) //i don't know what means dot here
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

void				put_pixel(int x, int y, int color, SDL_Surface *sur)
{
	int				*pixels;

	pixels = (int *)sur->pixels;
	pixels[sur->w * y + x] = color;
}

void				cycle_sdl(SDL_Window *win)
{
	SDL_Event		event;

	while (1)
	{
		if (SDL_PollEvent(&(event)))
		{
			if (SDL_QUIT == event.type)
				break ;
			if (SDLK_ESCAPE == event.key.keysym.sym)
				break ;
			SDL_UpdateWindowSurface(win);
		}
	}
}

t_vector			canvas_to_viewport(int x, int y, t_rt *rt)
{
	t_vector		vector;
	vector.x = (double)x * 1.f / rt->sdl.sur->h;
	vector.y = (double)y * 1.f / rt->sdl.sur->h;
	vector.z = 1; //расстояние от плоскости до проекции
	return (vector);
}

void	intersectraysphere(t_rt *rt, t_point o, t_vector d, t_figures figure)
{
	t_vector	oc;
	double		k1;
	double		k2;
	double		k3;
	double		discriminant;

	oc.x = o.x - figure.point.x;
	oc.y = o.y - figure.point.y;
	oc.z = o.z - figure.point.z;
	k1 = vec_dot(d, d);
	k2 = 2 * vec_dot(oc, d);
	k3 = vec_dot(oc, oc) - figure.radius * figure.radius;
	discriminant = k2 * k2 - 4 * k1 * k3;
	if (discriminant < 0)
	{
		rt->calculate.t1 = INFINITY;
		rt->calculate.t2 = INFINITY;
	}
	rt->calculate.t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
	rt->calculate.t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
}

void		init_figure(t_figures *figure)
{
	figure->radius = 0;
	figure->color = rgb(0, 0, 0);
	figure->radius = 0;	
	figure->point.x = 0;	
	figure->point.y = 0;	
	figure->point.z = 0;	
}

int					ray_trace(t_point point, t_vector vector, double min,
						double max, t_rt *rt)
{
	double		closest_t;
	t_figures	figure;
	t_figures	*tmp = rt->figure;

	closest_t = INFINITY;
	init_figure(&figure);
	while (tmp)
	{
		intersectraysphere(rt, point, vector, *tmp);
		if (rt->calculate.t1 >= min && rt->calculate.t1 <= max && rt->calculate.t1 < closest_t)
		{
			closest_t = rt->calculate.t1;
			figure = *tmp;
		}
		if (rt->calculate.t2 >= min && rt->calculate.t2 <= max && rt->calculate.t2 < closest_t)
		{
			closest_t = rt->calculate.t2;
			figure = *tmp;
		}
		tmp = tmp->next;
	}
	if (figure.radius == 0)
		return (rgb(255, 255, 255));
	return (figure.color);
}

void				for_each(t_rt *rt)
{
	int				x;
	int				y;
	t_vector		vector;
	t_point			point;
	int				color;

	y = -rt->sdl.sur->h / 2 - 1;
	while (++y < rt->sdl.sur->h / 2)
	{
		x = -rt->sdl.sur->w / 2 - 1;
		while (++x < rt->sdl.sur->w / 2)
		{
			vector = canvas_to_viewport(x, y, rt);
			color = ray_trace(point, vector, 1, INFINITY, rt);
			put_pixel(x + rt->sdl.sur->w / 2, y + rt->sdl.sur->h / 2, color, rt->sdl.sur);
		}
	}
}

void				init_sdl(t_rt *rt)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_exit("SDL_Init");
	if (!(rt->sdl.win =  SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP)))
		ft_exit("SDL_CreateWindow");
	if (!(rt->sdl.sur = SDL_GetWindowSurface(rt->sdl.win)))
		ft_exit("SDL_GetWindowSurface");
	for_each(rt);
	cycle_sdl(rt->sdl.win);
	SDL_DestroyWindow(rt->sdl.win);
	SDL_Quit();
}






















































// double		vec_dot(t_vector a, t_vector b) //i don't know what means dot here
// {
// 	return (a.x * b.x + a.y * b.y + a.z * b.z);
// }

// void				put_pixel(int x, int y, int color, SDL_Surface *sur)
// {
// 	int				*pixels;

// 	pixels = (int *)sur->pixels;
// 	pixels[sur->w * y + x] = color;
// }

// void				cycle_sdl(SDL_Window *win)
// {
// 	SDL_Event		event;

// 	while (1)
// 	{
// 		if (SDL_PollEvent(&(event)))
// 		{
// 			if (SDL_QUIT == event.type)
// 				break ;
// 			if (SDLK_ESCAPE == event.key.keysym.sym)
// 				break ;
// 			SDL_UpdateWindowSurface(win);
// 		}
// 	}
// }

// t_vector			canvas_to_viewport(int x, int y)
// {
// 	t_vector		vector;
// 	vector.x = (double)x * 1.f / WIDTH;
// 	vector.y = (double)y * 1.f / WIDTH;
// 	vector.z = 0.2; //расстояние от плоскости до проекции
// 	return (vector);
// }

// void	intersectraysphere(t_rt *rt, t_point o, t_vector d, t_figures figure)
// {
// 	t_vector	oc;
// 	double		k1;
// 	double		k2;
// 	double		k3;
// 	double		discriminant;

// 	oc.x = o.x - figure.point.x;
// 	oc.y = o.y - figure.point.y;
// 	oc.z = o.z - figure.point.z;
// 	k1 = vec_dot(d, d);
// 	k2 = 2 * vec_dot(oc, d);
// 	k3 = vec_dot(oc, oc) - figure.radius * figure.radius;
// 	discriminant = k2 * k2 - 4 * k1 * k3;
// 	if (discriminant < 0)
// 	{
// 		rt->calculate.t1 = INFINITY;
// 		rt->calculate.t2 = INFINITY;
// 	}
// 	rt->calculate.t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
// 	rt->calculate.t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
// }

// void		init_figure(t_figures *figure)
// {
// 	figure->radius = 0;
// 	figure->color = rgb(20, 20, 20);
// 	figure->radius = 0;	
// 	figure->point.x = 0;	
// 	figure->point.y = 0;	
// 	figure->point.z = 0;	
// }

// int					ray_trace(t_point point, t_vector vector, double min,
// 						double max, t_rt *rt)
// {
// 	double		closest_t;
// 	t_figures	figure;
// 	t_figures	tmp = rt->figure;

// 	closest_t = INFINITY;
// 	init_figure(&figure);
// 	// printf("%d\n", tmp.color);
// 	// while (&tmp)
// 	// {
// 		intersectraysphere(rt, point, vector, tmp);
// 		if (rt->calculate.t1 >= min && rt->calculate.t1 <= max && rt->calculate.t1 < closest_t)
// 		{
// 			closest_t = rt->calculate.t1;
// 			figure = tmp;
// 		}
// 		if (rt->calculate.t2 >= min && rt->calculate.t2 <= max && rt->calculate.t2 < closest_t)
// 		{
// 			closest_t = rt->calculate.t2;
// 			figure = tmp;
// 		}
// 	// }
// 	if (figure.radius == 0)
// 		return (rgb(255, 255, 255));
// 	return (figure.color);
// }

// void				for_each(t_rt *rt)
// {
// 	int				x;
// 	int				y;
// 	t_vector		vector;
// 	t_point			point;
// 	int				color;

// 	y = -rt->height / 2 - 1;
// 	while (++y < rt->height / 2)
// 	{
// 		x = -rt->width / 2 - 1;
// 		while (++x < rt->width / 2)
// 		{
// 			vector = canvas_to_viewport(x, y);
// 			color = ray_trace(point, vector, 1, INFINITY, rt);
// 			put_pixel(x + rt->width / 2, y + rt->height / 2, color, rt->sdl.sur);
// 		}
// 	}
// }

// void				init_sdl(t_rt *rt)
// {
// 	if (SDL_Init(SDL_INIT_VIDEO) != 0)
// 		ft_exit("SDL_Init");
// 	if (!(rt->sdl.win =  SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,
// 		SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0)))
// 		ft_exit("SDL_CreateWindow");
// 	if (!(rt->sdl.sur = SDL_GetWindowSurface(rt->sdl.win)))
// 		ft_exit("SDL_GetWindowSurface");
// 	for_each(rt);
// 	cycle_sdl(rt->sdl.win);
// 	SDL_DestroyWindow(rt->sdl.win);
// 	SDL_Quit();
// }
