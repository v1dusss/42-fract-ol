/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:14:43 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/01 20:02:41 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//typedef struct {
//    int r;
//    int g;
//    int b;
//}	t_color;

//uint32_t	mapToColor(int value, int max_value)
//{
//    t_color color;

//    // Calculate the proportion of the value to the maximum value
//    double proportion = (double)value / max_value;

//    // Interpolate between black (0, 0, 0) and white (255, 255, 255) based on the proportion
//    color.r = (1 - proportion) * 255;
//    color.g = (1 - proportion) * 255;
//    color.b = (1 - proportion) * 255;

//    return (get_rgb_a(color.r, color.g, color.b, 255));
//}


void	mandelbrot(t_master *master)
{
	clear_px(master->px);
	//master->px->b = (((master->fract->window_y / -2) + master->fract->y) / 80000);
	//master->px->a = (((master->fract->window_x / -2) + master->fract->x) / 80000) - 1.478;
	master->px->b = (((master->fract->window_y / -2) + master->fract->y) / 350);
	master->px->a = (((master->fract->window_x / -2) + master->fract->x) / 350) - 0.5;
	master->px->ca = master->px->a;
	master->px->cb = master->px->b;
	while (master->px->i < 1000)
	{
		master->px->aa = master->px->a * master->px->a - master->px->b * master->px->b;
		master->px->bb = 2 * master->px->a * master->px->b;
		master->px->a = master->px->aa + master->px->ca;
		master->px->b = master->px->bb + master->px->cb;
		if ((master->px->a + master->px->b) > 16)
			break ;
		master->px->i++;
	}
	//if (master->fract->x == (master->fract->window_x / 2) || master->fract->y == (master->fract->window_y / 2))
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y,
	//		get_rgb_a(255, 255, 255, 255));
	if (master->px->i == 1000)
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(0, 0, 0, 255));
	else
	{
		
		mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(master->px->i * 255 / 150, master->px->i * 255 / 2000, master->px->i * 255 / 2000, 255));
	}
	//else if (master->px->i > 40)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(255, 255, 255, 255));
	//else if (master->px->i > 35)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(0, 255, 0, 255));
	//else if (master->px->i > 27)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(0, 200, 50, 255));
	//else if (master->px->i > 26)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(0, 150, 90, 255));
	//else if (master->px->i > 23)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(0, 50, 200, 255));
	//else if (master->px->i > 20)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(0, 0, 255, 255));
	//else if (master->px->i > 17)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(50, 0, 150, 255));
	//else if (master->px->i > 16)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(150, 0, 100, 255));
	//else if (master->px->i > 15)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(255, 0, 0, 255));
	//else if (master->px->i > 14)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(255, 0, 180, 255));
	//else if (master->px->i > 13)
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(225, 0, 200, 255));
	//else
	//	mlx_put_pixel(master->img, master->fract->x, master->fract->y, get_rgb_a(0, 0, 0, 255));
}













unction main() {
  Logger.log(getAllPartnerNames());
  setContactPersonPartnerDropdown();
  setSpendenPartnerDropdown();
  setInternshipsPartnerDropdown();
  internshipStats();
  makeRanking();
}

function getAllPartnerNames() {
  var app = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/1O9qho7eCD_PKQCSTQ0O8DDhjqY_5eqg4Ts9xztAoykY/edit");
  var spreadsheet = app.getSheetByName("Partner")
  var numPartners = spreadsheet.getLastRow();
  var range = spreadsheet.getRange(2, 1, numPartners - 1);
  var partners = range.getValues();
  return (partners);
}

function getPartnerNameRange() {
  var app = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/1O9qho7eCD_PKQCSTQ0O8DDhjqY_5eqg4Ts9xztAoykY/edit");
  var spreadsheet = app.getSheetByName("Partner")
  var numPartners = spreadsheet.getLastRow();
  var range = spreadsheet.getRange(2, 1, numPartners);
  return (range);
}

function getStuedentNameRange() {
  var app = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/1O9qho7eCD_PKQCSTQ0O8DDhjqY_5eqg4Ts9xztAoykY/edit");
  var spreadsheet = app.getSheetByName("Student")
  var numStudents = spreadsheet.getLastRow();
  var range = spreadsheet.getRange(2, 1, numStudents);
  return (range);
}

// **********************************************************************************************************************************

function setContactPersonPartnerDropdown() {
  var app = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/1O9qho7eCD_PKQCSTQ0O8DDhjqY_5eqg4Ts9xztAoykY/edit");
  var spreadsheet = app.getSheetByName("Kontaktpersonen");
  var numContactPersons = spreadsheet.getLastRow();
  var range = spreadsheet.getRange(2, 5, numContactPersons - 1);
  
  var rule = SpreadsheetApp.newDataValidation().requireValueInRange(getPartnerNameRange(), true).build();
  range.setDataValidation(rule);
}

function setSpendenPartnerDropdown() {
  var app = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/1O9qho7eCD_PKQCSTQ0O8DDhjqY_5eqg4Ts9xztAoykY/edit");
  var spreadsheet = app.getSheetByName("Spenden");
  var numSpenden = spreadsheet.getLastRow();
  var range = spreadsheet.getRange(2, 1, numSpenden);

  var rule = SpreadsheetApp.newDataValidation().requireValueInRange(getPartnerNameRange(), true).build();
  range.setDataValidation(rule);  
}

function setInternshipsPartnerDropdown() {
  var app = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/1O9qho7eCD_PKQCSTQ0O8DDhjqY_5eqg4Ts9xztAoykY/edit");
  var spreadsheet = app.getSheetByName("Internships");
  var column = spreadsheet.getRange(2,2, spreadsheet.getLastRow());
  var values = column.getValues();
  Logger.log(values);
  values = values.filter((value) => value != '')
  Logger.log(values);
  var height = values.length;
  var range = spreadsheet.getRange(2, 1, height);

  var rule = SpreadsheetApp.newDataValidation().requireValueInRange(getPartnerNameRange(), true).build();
  range.setDataValidation(rule);  
}

function setInternshipsStudentDropdown() {
  var app = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/1O9qho7eCD_PKQCSTQ0O8DDhjqY_5eqg4Ts9xztAoykY/edit");
  var spreadsheet = app.getSheetByName("Internships");
  var column = spreadsheet.getRange(2,2, spreadsheet.getLastRow());
  var values = column.getValues();
  Logger.log(values);
  values = values.filter((value) => value != '')
  Logger.log(values);
  var height = values.length;
  var range = spreadsheet.getRange(2, 2, height);

  var rule = SpreadsheetApp.newDataValidation().requireValueInRange(getStudentNameRange(), true).build();
  range.setDataValidation(rule);  
}

function setIntershipStudentDropdown() {
  var app = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/1O9qho7eCD_PKQCSTQ0O8DDhjqY_5eqg4Ts9xztAoykY/edit");
  var spreadsheet = app.getSheetByName("Internships");
  var numSpenden = spreadsheet.getLastRow();
  var range = spreadsheet.getRange(2, 2, numSpenden);

  var rule = SpreadsheetApp.newDataValidation().requireValueInRange(getStudentNameRange(), true).build();
  range.setDataValidation(rule);  
}

function internshipStats() {
  var app = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/1O9qho7eCD_PKQCSTQ0O8DDhjqY_5eqg4Ts9xztAoykY/edit");
  var spreadsheet = app.getSheetByName("Internships");
}

function makeRanking() {
  var app = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/1O9qho7eCD_PKQCSTQ0O8DDhjqY_5eqg4Ts9xztAoykY/edit");
  var spreadsheet = app.getSheetByName("Ranking");
  var partners = getAllPartnerNames();
  for (let i = 0; i < partners.length; i++)
  {
    spreadsheet.getRange(2 + i, 1).setValue(partners[i]);
  }
  var spenden_spreadsheet = app.getSheetByName("Spenden");
  var spenden = spenden_spreadsheet.getRange(2, 1, spenden_spreadsheet.getLastRow(), 3).getValues();
  for (let i = 0; i < partners.length; i++)
  {
    var row = spenden.filter((row) => row[0] == partners[i])[0];
    if(row != null)
    {
      spreadsheet.getRange(2 + i, 2).setValue(row[2] * spreadsheet.getRange(1, 18).getValue());
    } else {
      spreadsheet.getRange(2 + i, 2).setValue(0);
    }
  }
  var column = spreadsheet.getRange(2,1, spreadsheet.getLastRow());
  //Logger.log(companies);
}























